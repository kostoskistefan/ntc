#ifndef NTC_h
#define NTC_h

#include <Arduino.h>

#ifdef ARDUINO_ARCH_STM32
    #define NTC_ADC_RESOLUTION 4095.0
#else
    #define NTC_ADC_RESOLUTION 1023.0
#endif

class NTC
{
    private:
        uint8_t pin;

    public:
        NTC(uint8_t _pin);

        void begin();

        int16_t getCelsius();
};

#endif
