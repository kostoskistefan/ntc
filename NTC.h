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
    NTC(uint8_t _pin) : pin(_pin) {}

    void begin()
    {
        pinMode(pin, INPUT);
    }

    int16_t getCelsius()
    {
        #ifndef NTC_INVERTED

            float Resistance = 10000 / (NTC_ADC_RESOLUTION / analogRead(pin) - 1.0);
            float steinhart = Resistance / 10000.0;
            steinhart = log(steinhart);
            steinhart /= 3435.0;
            steinhart += 1.0 / 298;
            steinhart = 1.0 / steinhart;
            return steinhart - 273;

        #else

            static float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
            float R = 10000 * (NTC_ADC_RESOLUTION / analogRead(pin) - 1.0);
            R = log(R);
            return (1.0 / (c1 + c2 * R + c3 * R * R * R)) - 273;

        #endif
    }
};

#endif
