#include "headers/mmu.h"
#include "headers/project.h"


//Well use the servos

void core3_main()
{
	mmu_init();   // Set mmu up on core 3
	core3_ready = true;

	while(1)
	{
		asm volatile ("nop");
	}
}
