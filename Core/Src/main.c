#include "main.h"
void Beep(uint16_t frequency)
{
    if (frequency == 0) {
        TIM3->CCR2 = 0;
        return;
    }

    uint16_t period = 1000000 / frequency;
    
    TIM3->ARR = period;
    TIM3->CCR2 = period / 2;
}

uint16_t adc;
uint32_t enc =0;
uint32_t duty;
uint16_t brightnes;
uint16_t flag = 0;
int position;
uint16_t brightness;
uint16_t pot1;
uint16_t pot2;
uint16_t pot3;


int main(void) {
    ADC_Init();
    FAN_BUZZER_Init();
    SET_BIT(ADC1->CR2, ADC_CR2_SWSTART);

    while (1) {
        pot1 = ADC_Read_Channel(9);
        pot2 = ADC_Read_Channel(3);
        pot3 = ADC_Read_Channel(4);
            
        TIM3->CCR1 =  pot3/4; 
    
        if(pot1 > 2500 && pot2 > 2500) {
            Beep(1000);
        }
        else if (pot1 > 2500 && pot2 < 2500) {
            Beep(2000);
        }
        else if (pot1 < 2500 && pot2 > 2500) {
            Beep(3000);
        }
        else {
            Beep(4000);
        }
    }
}  