#include <stdio.h>
#include "pico/stdlib.h"

#define btnA 5
const uint RGB[] = {11, 12, 13};
const bool colors[8][3] = {
    {0, 0, 0}, //desligado
    {0, 0, 1}, //vermelho
    {0, 1, 0}, //azul
    {1, 0, 0}, //verde
    {1, 1, 0}, //ciano
    {1, 0, 1}, //amarelo
    {0, 1, 1}, //magenta
    {1, 1, 1}, //branco
}; 

void set_rgb(int passo){
    for(int i; i < 3; i++){
        gpio_put(RGB[i], colors[passo][i]);
    }
}
int main()
{
    stdio_init_all();
    uint passo = 0;
    for(int i=0; i < 3;i++){
        gpio_init(RGB[i]);
        gpio_set_dir(RGB[i], GPIO_OUT);
    }

    gpio_init(btnA);
    gpio_set_dir(btnA, GPIO_IN);
    gpio_pull_up(btnA);

    while(true){
        if(gpio_get(btnA)){
            passo = (passo + 1) % 8;
            while(gpio_get(btnA)){
                sleep_ms(50);
            }
        }
        set_rgb(passo);
    }
    }
