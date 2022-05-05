#include <stdio.h>
#include "blink.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define led1 2
void blink(void)
{
    gpio_set_direction(led1, GPIO_MODE_OUTPUT);
    while(1)
    {
        gpio_set_level(led1,1);
        printf("Led is On\n");
        vTaskDelay(100);
        gpio_set_level(led1,0);
        printf("Led is Off\n");
        vTaskDelay(100);
    }
}
