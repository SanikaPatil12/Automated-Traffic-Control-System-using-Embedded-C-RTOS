/* Minimal LPC1768 GPIO helpers.
THIS IS A TEMPLATED IMPLEMENTATION. Replace with vendor SDK / CMSIS functions
according to your development environment (Keil / MCUXpresso / GCC). */


#include "gpio.h"
#include "lpc17xx.h" // If using LPC17xx CMSIS, otherwise remove and implement accordingly


void gpio_init(void)
{
// Enable GPIO power/clock if necessary - LPC176x uses power by default after reset
// Configure P0.[0..8] as outputs
LPC_PINCON->PINSEL0 &= ~((3UL<<0) | (3UL<<2) | (3UL<<4) | (3UL<<6) | (3UL<<8) | (3UL<<10));
LPC_GPIO0->FIODIR |= (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<8);


// Set all low initially
LPC_GPIO0->FIOCLR = (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<8);
}


void gpio_write(uint32_t pin, uint8_t value)
{
if (value)
LPC_GPIO0->FIOSET = (1<<pin);
else
LPC_GPIO0->FIOCLR = (1<<pin);
}


void gpio_toggle(uint32_t pin)
{
if (LPC_GPIO0->FIOPIN & (1<<pin))
LPC_GPIO0->FIOCLR = (1<<pin);
else
LPC_GPIO0->FIOSET = (1<<pin);
}
