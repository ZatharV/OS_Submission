#include "priority.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define led 2

TaskHandle_t hello_world;
TaskHandle_t blink;

void blink_code(void *pvParameter)
{
    gpio_set_direction(led, GPIO_MODE_OUTPUT);
    int isON = 0;

    for(;;)
    { 
        gpio_set_level(led, isON);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        printf("LED is %s on core %d with priority %d\n",isON == true ? "ON" : "OFF", xPortGetCoreID(), uxTaskPriorityGet(blink));
        isON = !isON;
    }
}
void hello_world_code(void *pvParameter)
{
    for(;;)
    { 
        printf("Hello world running on core %d! and prority %d \n", xPortGetCoreID(), uxTaskPriorityGet(hello_world));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void priority()
{ 
    xTaskCreatePinnedToCore(hello_world_code, "task1", 10000, NULL, 3, &hello_world, 0);
    xTaskCreatePinnedToCore(blink_code, "task2", 10000, NULL, 17, &blink, 0);
}