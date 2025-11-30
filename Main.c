/* main.c - RTOS entry & initialization for LPC1768 */



#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "gpio.h"
#include <stdio.h>


/* Task prototypes */
void vTrafficTask(void *pvParameters);
void vTimerTask(void *pvParameters);
void vBuzzerTask(void *pvParameters);


/* Shared objects */
SemaphoreHandle_t xTransitionSemaphore; // gives buzzer a signal to buzz
SemaphoreHandle_t xPhaseMutex; // protect current_phase_seconds
volatile uint32_t current_phase_remaining_seconds = 0;


int main(void)
{
SystemInit(); // CMSIS system init (clock)
gpio_init(); // initialize gpio pins


// Create synchronization primitives
xTransitionSemaphore = xSemaphoreCreateBinary();
xPhaseMutex = xSemaphoreCreateMutex();


if (xTransitionSemaphore == NULL || xPhaseMutex == NULL) {
// handle allocation failure
while (1);
}


// Create tasks
xTaskCreate(vTrafficTask, "Traffic", 512, NULL, 3, NULL);
xTaskCreate(vTimerTask, "Timer", 256, NULL, 2, NULL);
xTaskCreate(vBuzzerTask, "Buzzer", 256, NULL, 4, NULL);


// Start scheduler
vTaskStartScheduler();


// Should never reach here
while(1) { }
return 0;
}
