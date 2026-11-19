#pragma once

/*

This class is a lightweight envelope inspired by the Maxwell-Boltzmann distribution.
It rises, then decays depending on the constants provided.
The maximum sound is achieved at p/r seconds.

*/

class Envelope {
    public:
        float r;
        float c;
        float p;
        float normConst;
        float phase;

        Envelope(float r, float p);

        float getNextSample(int sampleRate);

        float envFunction(float x);

        void normalize();
};