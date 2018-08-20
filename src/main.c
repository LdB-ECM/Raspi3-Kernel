#include "headers/project.h"
#include "headers/mmu.h"



static uint32_t check_hello = 0;

void main()
{
	// set up serial console
	//uart_init();
	lfb_init();

	// Create mmu table on Core0
	init_page_table();

	dynamic_memory_alloc_init();
	console_init();	
	clocks_init();


	start_other_3_cores();   // Each start will apply mmu to that core
	mmu_init();  // Now turn MMU on core 0
	*core0_ready = true;

	printf("4 cores with MMU online\r\n");
	semaphore_inc(&check_hello); // lock hello semaphore .. if MMU is not working it will lock here
	printf("Semaphore count\n", check_hello);
	semaphore_dec(&check_hello);
	printf("Semaphore count\n", check_hello);

	// echo everything back
	while(1) 
	{
		uart_send(uart_getc());
	}
}
