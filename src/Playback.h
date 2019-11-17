#pragma once

#include "common.h"

#include <portaudio.h>

class Playback {
public:
  Playback(PaStream *stream);
  ~Playback();
  void wait(int num_seconds = 10);

private:
  PaStream *stream;
};
