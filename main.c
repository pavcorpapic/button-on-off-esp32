#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_2
#define BUTTON_PIN_ON GPIO_NUM_14
#define BUTTON_PIN_OFF GPIO_NUM_15

int app_main(){
  gpio_config(LED_PIN);
  gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

  gpio_config(BUTTON_PIN_ON);
  gpio_set_direction(BUTTON_PIN_ON, GPIO_MODE_INPUT);
  gpio_set_pull_mode(BUTTON_PIN_ON, GPIO_PULLUP_ONLY);

  gpio_config(BUTTON_PIN_OFF);
  gpio_set_direction(BUTTON_PIN_OFF, GPIO_MODE_INPUT);
  gpio_set_pull_mode(BUTTON_PIN_OFF, GPIO_PULLUP_ONLY);
while(1){
  if(gpio_get_level(BUTTON_PIN_ON)==0){
    gpio_set_level(LED_PIN, 1);
  }
  if(gpio_get_level(BUTTON_PIN_OFF)==0){
    gpio_set_level(LED_PIN,0);
  }
  vTaskDelay(10/ portTICK_PERIOD_MS);
   }
}
