#ifndef NTC_H
#define NTC_H

#include <Arduino.h>

class NTC
{
    private:
        uint8_t pin;

    public:
        NTC(const uint8_t pin);
        int16_t getCelsius();
};

#endif // NTC_H
