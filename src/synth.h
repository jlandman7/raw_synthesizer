#pragma once
#include <iostream>
#include "envelope.h"
#include "sinOscillator.h"

class Synthesizer {
    public:
        Envelope env;
        SinOscillator sinOsc;
        Synthesizer(Envelope env, SinOscillator sinOsc) : env(env), sinOsc(sinOsc) {};

        float getNextSample(int sampleRate) {
            float sample = env.getNextSample(sampleRate) * sinOsc.getSample(sampleRate);
            return sample;
        }
};