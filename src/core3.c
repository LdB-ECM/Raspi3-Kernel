#include "headers/mmu.h"
#include "headers/project.h"


//Well use the servos

void core3_main()
{
	*core3_ready = true;
	mmu_init();   // Set mmu up on core 3

	while(1)
	{
		asm volatile ("nop");
	}
}
