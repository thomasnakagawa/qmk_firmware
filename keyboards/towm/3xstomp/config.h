// Copyright 2024 Thomas Nakagawa (@Thomas Nakagawa)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define AUDIO_VOICES
#define AUDIO_PIN C6
#define STARTUP_SONG SONG(CLUEBOARD_SOUND)
#define AUDIO_INIT_DELAY

#define AUDIO_CLICKY

#define AUDIO_CLICKY_FREQ_DEFAULT 4000.0f
#define AUDIO_CLICKY_FREQ_MAX 5000.0f
#define AUDIO_CLICKY_FREQ_MIN 2000.0f

#define MATRIX_ROWS 3
#define MATRIX_COLS 3

#define DIRECT_PINS { \
  { NO_PIN, F4, NO_PIN}, \
  { NO_PIN, F5, NO_PIN }, \
  { D3, D2, D1 } \
}

#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }
#define ENCODER_RESOLUTION 4
