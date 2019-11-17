#include "Playback.h"

Playback::Playback(PaStream *stream) : stream(stream) {
  PaError err = Pa_StartStream(stream);
  PA_ERROR(err);
}

Playback::~Playback() {
  PaError err = Pa_StopStream(stream);
  PA_ERROR(err);
}

void Playback::wait(int num_seconds) { Pa_Sleep(num_seconds * 1000); }
