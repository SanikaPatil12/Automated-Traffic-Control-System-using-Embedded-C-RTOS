#ifndef GPIO_H
#define GPIO_H


#include <stdint.h>


// Replace these pin constants with board-specific pin encoding if needed
#define PIN_P0_0 0
#define PIN_P0_1 1
#define PIN_P0_2 2
#define PIN_P0_3 3
#define PIN_P0_4 4
#define PIN_P0_5 5
#define PIN_P0_8 8


void gpio_init(void);
void gpio_write(uint32_t pin, uint8_t value);
void gpio_toggle(uint32_t pin);


#endif // GPIO_H
