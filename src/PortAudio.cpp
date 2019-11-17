#include "PortAudio.h"
#include "Playback.h"

#include <cassert>
#include <cstdio>

#include <portaudio.h>

PortAudio::PortAudio() : mInitializedProperly(true) {
  PaError err = Pa_Initialize();
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    assert(err == paNoError);
    mInitializedProperly = false;
  }
}

PortAudio::~PortAudio() {
  if (mInitializedProperly) {
    PaError err = Pa_Terminate();
    PA_ERROR(err);
  }
}

paTestData PortAudio::data = {0.f, 0.f};

void PortAudio::openDefault() {
  PaStream *stream;
  PaError err;

  err = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, SAMPLE_RATE, 256,
                             PortAudio::patestCallback, &(PortAudio::data));
  PA_ERROR(err);

  Playback playback(stream);

  playback.wait(10);
}
