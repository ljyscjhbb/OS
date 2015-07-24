/*
 * =====================================================================================
 *
 *       Filename:  clock.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年7月22日 12时06分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *
 * =====================================================================================
 */

#include "common.h"
#include "debug.h"
#include "const.h"
#include "elf.h"
#include "gdt.h"
#include "idt.h"
#include "multiboot.h"
#include "pmm.h"
#include "console.h"
#include "keymap.h"
#include "string.h"


/*======================================================================*
                           clock_handler
 *======================================================================*/
PUBLIC void clock_handler(int irq)
{
	ticks++;
	p_proc_ready->ticks--;

	if (k_reenter != 0) {
		return;
	}

	if (p_proc_ready->ticks > 0) {
		return;
	}

	schedule();

}

/*======================================================================*
                              milli_delay
 *======================================================================*/
PUBLIC void milli_delay(int milli_sec)
{
        int t = get_ticks();

        while(((get_ticks() - t) * 1000 / HZ) < milli_sec) {}
}

/*======================================================================*
                           init_clock
 *======================================================================*/
PUBLIC void init_clock()
{
        /* 初始化 8253 PIT */
        out_byte(TIMER_MODE, RATE_GENERATOR);
        out_byte(TIMER0, (u8) (TIMER_FREQ/HZ) );
        out_byte(TIMER0, (u8) ((TIMER_FREQ/HZ) >> 8));

        put_irq_handler(CLOCK_IRQ, clock_handler);    /* 设定时钟中断处理程序 */
        enable_irq(CLOCK_IRQ);                        /* 让8259A可以接收时钟中断 */
}


