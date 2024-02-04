#include "NTC.h"

#define NUMBER_OF_READINGS 10

NTC::NTC(const uint8_t pin)
{
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

int16_t NTC::getCelsius()
{
    float temperature_sum = 0;
    uint16_t adc_value = 0;

    for (uint8_t i = 0; i < NUMBER_OF_READINGS; ++i)
    {
        adc_value = analogRead(this->pin);
        temperature_sum += (3435.0 / (11.5268456 + log(adc_value / (1023.0 - adc_value)))) - 273.15;
        delay(10);
    }
    
    return (int16_t) (temperature_sum / NUMBER_OF_READINGS);
}
