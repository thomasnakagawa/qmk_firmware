// Copyright 2024 Thomas Nakagawa (@Thomas Nakagawa)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTION 4

#define DIP_SWITCH_PINS { F4, F5 }

#define AUDIO_PIN B6
#define STARTUP_SONG SONG(STARTUP_SOUND)
#define AUDIO_INIT_DELAY
