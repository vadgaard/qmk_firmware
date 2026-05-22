/* Copyright 2026 Lars Boberg Vadgaard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 */

#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

// Most tactile encoders have detents every 4 stages.
#define ENCODER_RESOLUTION 4
