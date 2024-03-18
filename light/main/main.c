#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define led GPIO_NUM_38
void led_init(){
    gpio_set_direction(led,GPIO_MODE_INPUT_OUTPUT);
    gpio_set_level(led,0);
}

void app_main(void)
{
    led_init();
    while(1)
    {
        gpio_set_level(led,!gpio_get_level(led));
        printf("led state:%d",gpio_get_level(led));
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

