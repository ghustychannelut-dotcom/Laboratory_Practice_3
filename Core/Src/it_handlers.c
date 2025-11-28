#include "it_handlers.h"

extern uint16_t adc;
extern uint16_t flag;

void ADC_IRQHandler(void)
{
    flag = 1;
    SET_BIT(ADC1->CR2, ADC_CR2_SWSTART); 
    adc =  ADC1->DR; 
    CLEAR_BIT(ADC1->SR, ADC_SR_EOC);
}