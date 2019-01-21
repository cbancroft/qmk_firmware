#pragma once

#ifdef AUDIO_ENABLE
#define AUDIO_CLICKY
#define STARTUP_SONG SONG(E1M1_DOOM)
#define GOODBYE_SONG  SONG(SONIC_RING)
#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND), \
                                  SONG(OVERWATCH_THEME) \
                                }

#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f

#endif

#ifndef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2
#endif // !ONESHOT_TAP_TOGGLE

#ifndef ONESHOT_LAYER_TOGGLE
#define ONESHOT_LAYER_TOGGLE 2
#endif // !ONESHOT_LAYER_TOGGLE

#ifndef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 3000
#endif// !ONESHOT_TIMEOUT

#ifndef QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 4
#endif // !QMK_KEYS_PER_SCAN

// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
// #define TAPPING_FORCE_HOLD
//#define RETRO_TAPPING

#define FORCE_NKRO

#ifndef TAPPING_TOGGLE
#define TAPPING_TOGGLE  1
#endif

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 175


/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Mouse Control Settings */
#ifdef MOUSEKEY_ENABLE
#define MOUSEKEY_INTERVAL     20
#define MOUSEKEY_DELAY        0
#define MOUSEKEY_TIME_TO_MAX  60
#define MOUSEKEY_MAX_SPEED    7

#define MOUSEKEY_WHEEL_DELAY  0
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#endif // !MOUSEKEY_ENABLE

// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define DISABLE_LEADER

#define MACRO_TIMER 5

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
