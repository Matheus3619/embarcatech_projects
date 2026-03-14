#include <stdio.h>
#include "pico/stdlib.h"

#define btnA 5
const uint RGB[] = {11, 12, 13};
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
            passo += 1;
            if(passo > 7){
                passo = 0;
            }
            while(gpio_get(btnA)){
                sleep_ms(50);
            }
        }

        switch (passo)
        {
        case 1:
        // vermelho
            gpio_put(RGB[0], 0);
            gpio_put(RGB[1], 0);
            gpio_put(RGB[2], 1);
            break;
        case 2:
        // verde
            gpio_put(RGB[0], 1);
            gpio_put(RGB[1], 0);
            gpio_put(RGB[2], 0);
            break;
        case 3:
        // azul
            gpio_put(RGB[0], 0);
            gpio_put(RGB[1], 1);
            gpio_put(RGB[2], 0);
            break;
        case 4:
        // amarelo
            gpio_put(RGB[0], 1);
            gpio_put(RGB[1], 0);
            gpio_put(RGB[2], 1);
            break;
        case 5:
        // ciano
            gpio_put(RGB[0], 1);
            gpio_put(RGB[1], 1);
            gpio_put(RGB[2], 0);
            break;
        case 6:
        // magenta
            gpio_put(RGB[0], 0);
            gpio_put(RGB[1], 1);
            gpio_put(RGB[2], 1);
            break;
        case 7:
        // branco
            gpio_put(RGB[0], 1);
            gpio_put(RGB[1], 1);
            gpio_put(RGB[2], 1);
            break;
        
        default:
            gpio_put(RGB[0], 0);
            gpio_put(RGB[1], 0);
            gpio_put(RGB[2], 0);
            break;
        }
    }

   
}
