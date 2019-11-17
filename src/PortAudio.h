#pragma once

#include "common.h"

#include <portaudio.h>

constexpr int SAMPLE_RATE(44100);

typedef struct {
  float left_phase;
  float right_phase;
} paTestData;

class PortAudio {
public:
  PortAudio();
  ~PortAudio();

  void openDefault();

private:
  bool mInitializedProperly;

public:
  // For callback
  static paTestData data;
  static int patestCallback(const void *inputBuffer, void *outputBuffer,
                            unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo *timeInfo,
                            PaStreamCallbackFlags statusFlags, void *userData) {

    paTestData *data = (paTestData *)userData;
    float *out = (float *)outputBuffer;
    (void)inputBuffer; // Prevent unused variable warning

    for (unsigned long i = 0; i < framesPerBuffer; ++i) {
      *out = data->left_phase;
      ++out;
      *out = data->right_phase;
      ++out;

      data->left_phase += 0.01f;
      if (data->left_phase >= 1.0f)
        data->left_phase -= 2.0f;

      data->right_phase += 0.03f;
      if (data->right_phase >= 1.0f)
        data->right_phase -= 2.0f;
    }

    return 0;
  }
};
