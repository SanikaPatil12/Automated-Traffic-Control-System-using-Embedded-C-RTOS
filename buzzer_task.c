/* buzzer_task.c - Buzzer alerts during transitions */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "gpio.h"


extern SemaphoreHandle_t xTransitionSemaphore;
#define BUZZER_PIN PIN_P0_8


void buzz_pulse(uint32_t ms)
{
gpio_write(BUZZER_PIN, 1);
vTaskDelay(pdMS_TO_TICKS(ms));
gpio_write(BUZZER_PIN, 0);
}


void vBuzzerTask(void *pvParameters)
{
(void) pvParameters;
for(;;)
{
// Wait for transition event
if (xSemaphoreTake(xTransitionSemaphore, portMAX_DELAY) == pdTRUE) {
// Short triple beep to indicate transition
for (int i = 0; i < 3; ++i) {
buzz_pulse(120);
vTaskDelay(pdMS_TO_TICKS(80));
}
}
}
}
