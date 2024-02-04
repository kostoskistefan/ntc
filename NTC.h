#ifndef NTC_H
#define NTC_H

#include <Arduino.h>
#include <cstdint>

#define NTC_ADC_RESOLUTION 1024.0
#define CONST_3435_OVER_298 11.52685

class NTC
{
    private:
        uint8_t pin;

    public:
        NTC(uint8_t _pin) : pin(_pin) {}

        void begin()
        {
            pinMode(this->pin, INPUT);
        }

        int16_t getCelsius()
        {
            #ifndef NTC_INVERTED
                const uint16_t adc_value = analogRead(this->pin);
                return (3435.0 / (log(adc_value / (NTC_ADC_RESOLUTION - adc_value)) + CONST_3435_OVER_298)) - 273;
            #else
                static float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
                float R = log(10000 * ((NTC_ADC_RESOLUTION / analogRead(pin)) - 1.0));
                return (1.0 / (c1 + c2 * R + c3 * R * R * R)) - 273;
            #endif
        }
};

#endif // NTC_H
