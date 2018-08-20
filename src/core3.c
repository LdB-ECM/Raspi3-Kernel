#include "headers/project.h"
#include "headers/mmu.h"

//Well use the servos

void core3_main()
{
	mmu_init();   // Set mmu up on core 3
	while(1)
	{
		asm volatile ("nop");
	}
}
