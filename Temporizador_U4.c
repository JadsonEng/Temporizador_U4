#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define Green 11
#define Yellow 12
#define Red 13

volatile int cont = 0;

bool repeating_timer_callback(struct repeating_timer *t)
{
  switch(cont){
    case 0: 
    gpio_put(Green, 0);
    gpio_put(Yellow, 0);
    gpio_put(Red, 1);
    break;
    case 1:
    gpio_put(Green, 0);
    gpio_put(Yellow, 1);
    gpio_put(Red, 0);
    break;
    case 2:
    gpio_put(Green, 1);
    gpio_put(Yellow, 0);
    gpio_put(Red, 0);
    break;
  }
  cont++;
  if (cont >= 3) cont = 0;
  return true;
}

int main(){

  stdio_init_all();

  // Inicializando os pinos
  gpio_init(Green);
  gpio_set_dir(Green, GPIO_OUT);
  gpio_init(Yellow);
  gpio_set_dir(Yellow, GPIO_OUT);
  gpio_init(Red);
  gpio_set_dir(Red, GPIO_OUT);

  struct repeating_timer timer;
  add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
  sleep_ms(3000);

  while (1){
    
    switch(cont-1){
    case 0: 
    printf("Stop!\n");
    break;
    case 1:
    printf("Atention!\n");
    break;
    case -1:
    printf("Go!\n");
    break;
  }
    
    sleep_ms(1000);
  }
}