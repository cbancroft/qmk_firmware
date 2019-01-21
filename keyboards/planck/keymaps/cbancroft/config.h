/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

#define PERMISSIVE_HOLD
                                    //#define TAPPING_TERM 500
#define IGNORE_MOD_TAP_INTERRUPT
                                    //#define IGNORE_STUCK_MODIFIERS
#define PREVENT_STUCK_MODIFIERS
#define TAPPING_TOGGLE 1
#define TAPPING_TERM 350
                                    //#define TAPPING_TERM 300
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_LAYER_TOGGLE 2
#define ONESHOT_TIMEOUT 400

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Mouse Control Settings */
#define MOUSEKEY_INTERVAL     20
#define MOUSEKEY_DELAY        0
#define MOUSEKEY_TIME_TO_MAX  60
#define MOUSEKEY_MAX_SPEED    7

#define MOUSEKEY_WHEEL_DELAY  0
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#endif
