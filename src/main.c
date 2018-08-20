#include "headers/project.h"
#include "headers/mmu.h"



static uint32_t check_hello = 0;

void main()
{
	// set up serial console
	//uart_init();
	lfb_init();

	// Start mmu on Core0
	init_page_table();
	mmu_init();

	dynamic_memory_alloc_init();
	console_init();	
	clocks_init();


	start_other_3_cores();   // Each start will apply mmu to that core
	
	printf("Wait on MMU on 4 cores\r\n");

	while (mmu_loaded != 4);  // Wait for all 4 cores to load MMU

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
