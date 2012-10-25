#include "types.h"
#include "ports.h"
#include "isr.h"
#include "printk.h"
#include "kbd.h"

#define KEY_DEVICE    0x60
#define KEY_PENDING   0x64

static void
keyboard_handler(struct registers *regs)
{
    uint16_t scancode;
    while(inb(KEY_PENDING) & 2);
    scancode = inb(KEY_DEVICE);
    printk(INFO, "Keyboard press: %d\n", scancode);
}

void
kbd__init(void)
{ 
    register_interrupt_handler(IRQ1, &keyboard_handler);
    
    /* This is already turned on. so dont register this. 
    outb(0x21, 0xfd);
    outb(0xa1, 0xff);
    */
}
