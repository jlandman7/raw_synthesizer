#pragma once
#include <cmath>
#include <iostream>

class SinOscillator {
    public:
        float amplitude;
        float frequency;
        double phase = 0.0;
        
        float getSample(int sampleRate) {
            float sample = amplitude * sin(phase);
            phaseIncrement(sampleRate);
            return sample;
        }

        void phaseIncrement(int sampleRate) {
            phase += (2 * M_PI * frequency / sampleRate);
            if (phase >= 2.0 * M_PI) {
                phase -= 2.0 * M_PI;
            }
        }

        SinOscillator(float amplitude, float frequency) 
            : amplitude(amplitude), frequency(frequency) {}
};