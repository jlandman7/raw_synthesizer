#include "envelope.h"
#include <cmath>


Envelope::Envelope(float r, float p) : r(r), p(p){
    normConst = 1.0f;
    phase = 0.0f;
    normalize();
}

float Envelope::getNextSample(int sampleRate) {
    float value = envFunction(phase);
    if (value > pow(10, -6) || phase < p/r) {
        phase += 1.0f/((float) sampleRate);
        return value;
    }
    else {
        return 0;
    }
}

float Envelope::envFunction(float x) {
    return pow(x, p) * exp(-r * x) / normConst;
}

void Envelope::normalize() {
    if (r < 0) {r = 1;}
    float criticalX = p/r;      // derivative = 0 at this x value
    float criticalValue = envFunction(criticalX);
    normConst = criticalValue;
}