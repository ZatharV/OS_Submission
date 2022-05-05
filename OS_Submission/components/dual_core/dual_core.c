#include <stdio.h>
#include "dual_core.h"
#include  "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define led1 2
TaskHandle_t Task1;
TaskHandle_t Task2;

void Task1code( void * parameter ){
  printf("Task1 is running on core %d\n",xPortGetCoreID());

  for(;;){
    gpio_set_level(led1,1);
    printf("Led ON on Core %d\n",xPortGetCoreID());
    vTaskDelay(100);
    gpio_set_level(led1,0);
    printf("Led OFF on Core %d\n",xPortGetCoreID());
    vTaskDelay(100);
  } 
}

void Task2code( void * parameter ){
    for(;;)
    {
        printf("Hello World running on core %d\n\n",xPortGetCoreID());
        vTaskDelay(100);
    }
}

void dual_core(void)
{
    gpio_set_direction(led1, GPIO_MODE_OUTPUT);
    xTaskCreatePinnedToCore(Task1code,"Task1",10000,NULL,1,&Task1,0);
    xTaskCreatePinnedToCore(Task2code,"Task2",10000,NULL,1,&Task2,1);
}
