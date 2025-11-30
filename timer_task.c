/* timer_task.c - countdown timer (prints to serial) */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include <stdio.h>


extern SemaphoreHandle_t xPhaseMutex;
extern volatile uint32_t current_phase_remaining_seconds;


void vTimerTask(void *pvParameters)
{
(void) pvParameters;
char buf[32];


for (;;) {
// Read remaining seconds and print once per second
if (xSemaphoreTake(xPhaseMutex, portMAX_DELAY) == pdTRUE) {
uint32_t rem = current_phase_remaining_seconds;
xSemaphoreGive(xPhaseMutex);


// Simple serial print. Replace with LCD / 7-seg driver if required.
snprintf(buf, sizeof(buf), "Countdown: %02lu
", (unsigned long)rem);
printf("%s", buf);
}
vTaskDelay(pdMS_TO_TICKS(1000));
}
}
