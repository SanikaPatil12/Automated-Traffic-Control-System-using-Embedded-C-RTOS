/* traffic_task.c - Traffic light state machine using FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "gpio.h"


extern SemaphoreHandle_t xTransitionSemaphore;
extern SemaphoreHandle_t xPhaseMutex;
extern volatile uint32_t current_phase_remaining_seconds;


#define RED_NS PIN_P0_0
#define YELLOW_NS PIN_P0_1
#define GREEN_NS PIN_P0_2


#define RED_EW PIN_P0_3
#define YELLOW_EW PIN_P0_4
#define GREEN_EW PIN_P0_5


#define BUZZER_PIN PIN_P0_8


// durations in seconds (configurable)
static const uint32_t RED_TIME = 10;
static const uint32_t GREEN_TIME = 10;
static const uint32_t YELLOW_TIME = 3;


static void set_ns(uint8_t r, uint8_t y, uint8_t g)
{
gpio_write(RED_NS, r);
gpio_write(YELLOW_NS, y);
gpio_write(GREEN_NS, g);
}


static void set_ew(uint8_t r, uint8_t y, uint8_t g)
{
gpio_write(RED_EW, r);
gpio_write(YELLOW_EW, y);
gpio_write(GREEN_EW, g);
}


void vTrafficTask(void *pvParameters)
{
(void) pvParameters;


// Initial state: NS Green, EW Red
for(;;)
{
// North-South Green, East-West Red
set_ns(0,0,1);
set_ew(1,0,0);
// set countdown
if (xSemaphoreTake(xPhaseMutex, portMAX_DELAY) == pdTRUE) {
current_phase_remaining_seconds = GREEN_TIME;
xSemaphoreGive(xPhaseMutex);
}
// Wait while allowing timer task to update
for (uint32_t t = 0; t < GREEN_TIME; ++t) {
vTaskDelay(pdMS_TO_TICKS(1000));
if (xSemaphoreTake(xPhaseMutex, 0) == pdTRUE) {
if (current_phase_remaining_seconds > 0) current_phase_remaining_seconds--;
xSemaphoreGive(xPhaseMutex);
}
}
}
