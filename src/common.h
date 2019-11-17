#pragma once

#include <cassert>
#include <cstdio>
#include <portaudio.h>

#define PA_ERROR(err)                                                          \
  if (err != paNoError) {                                                      \
    printf("portaudio error: %s\n", Pa_GetErrorText(err));                     \
    assert(err == paNoError);                                                  \
  }
