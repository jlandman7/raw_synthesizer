#include <iostream>
#include <SDL.h>

#include "sinOscillator.h"
#include "envelope.h"
#include "synth.h"

void audioCallback(void* userdata, Uint8* stream, int len) {
    Synthesizer* synth = static_cast<Synthesizer*>(userdata);
    float* buffer = reinterpret_cast<float*>(stream);
    int numSamples = len / sizeof(float);

    static constexpr double SAMPLE_RATE = 48000.0;

    for (int i = 0; i < numSamples; i += 2) {
        float sample = synth->getNextSample(SAMPLE_RATE);

        buffer[i] = sample;
        buffer[i + 1] = sample;
    }
}

int main() {
    SDL_Init(SDL_INIT_AUDIO);
    
    SinOscillator sinOsc = SinOscillator(1, 440);
    Envelope env = Envelope(5, 2);
    Synthesizer synth = Synthesizer(env, sinOsc);

    SDL_AudioSpec spec{};
        spec.freq = 48000;
        spec.format = AUDIO_F32SYS;
        spec.channels = 2;
        spec.samples = 1024;
        spec.callback = audioCallback;
        spec.userdata = &synth;

    SDL_AudioSpec obtained{};

    SDL_AudioDeviceID device = SDL_OpenAudioDevice(nullptr, 0, &spec, &obtained, 0);

    SDL_PauseAudioDevice(device, 0);
    SDL_Delay(3000);
    SDL_PauseAudioDevice(device, 1);
    SDL_CloseAudioDevice(device);

    SDL_Quit();
    return 0;
}

