/*
Copyright 2018 Charles Bancroft <charlie.bancroft@gmail.com> @cbancroft

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

#include "cbancroft.h"
#include "version.h"
#include "eeprom.h"

#ifdef AUDIO_ENABLE
float song_startup[][2] = SONG(STARTUP_SOUND);
float song_colemak[][2] = SONG(COLEMAK_SOUND);
float song_qwerty[][2] = SONG(QWERTY_SOUND);
float song_dvorak[][2] = SONG(DVORAK_SOUND);
#endif

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps

__attribute__((weak)) void matrix_init_keymap(void) {}

__attribute__((weak)) void startup_keymap(void) {}

__attribute__((weak)) void suspend_power_down_keymap(void) {}

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

__attribute__((weak)) void matrix_scan_keymap(void) {}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record)
{
  return true;
}

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record)
{
  return true;
}

__attribute__((weak))
uint32_t
layer_state_set_keymap(uint32_t state)
{
  return state;
}

__attribute__((weak))
uint32_t
default_layer_state_set_keymap(uint32_t state)
{
  return state;
}

__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}

void startup_user(void)
{
#ifdef RGBLIGHT_ENABLE
  matrix_init_rgb();
#endif //RGBLIGHT_ENABLE
  startup_keymap();
}

void suspend_power_down_user(void)
{
  suspend_power_down_keymap();
}

void suspend_wakeup_init_user(void)
{
  suspend_wakeup_init_keymap();
#ifdef KEYBOARD_ergodox_ez
  wait_ms(10);
#endif
}

// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void)
{
  static bool has_ran_yet;
  if (!has_ran_yet)
  {
    has_ran_yet = true;
    startup_user();
  }

#ifdef TAP_DANCE_ENABLE
  //Macro checking code here
#endif // TAP_DANCE_ENABLE

#ifdef RGBLIGHT_ENABLE
  matrix_scan_rgb();
#endif // RGBLIGHT_ENABLE

  matrix_scan_keymap();
}

// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void)
{
  // Keymap specific things, do it first thing to allow for delays etc
  matrix_init_keymap();

  // Correct unicode
#ifdef UNICODE_ENABLE
  set_unicode_input_mode(UC_LNX);
#endif

  // Make beginning layer COLEMAK
  set_single_persistent_default_layer(_COLEMAK);
}

// Defines actions for custom keycodes defined in user header
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case QWERTY:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  case COLEMAK:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_COLEMAK);
    }
    return false;
    break;
  case DVORAK:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer( _DVORAK);
    }
    return false;
    break;
  case SYMBOL:
    if (record->event.pressed)
    {
      layer_on(_SYMBOL);
      update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
    }
    else
    {
      layer_off(_SYMBOL);
      update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed)
    {
      layer_on(_RAISE);
      update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
    }
    else
    {
      layer_off(_RAISE);
      update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
    }
    return false;
    break;
  case ADJUST:
    if (record->event.pressed)
    {
      layer_on(_ADJUST);
    }
    else
    {
      layer_off(_ADJUST);
    }
    return false;
    break;
  }
  return true;
}

bool music_mask_user(uint16_t keycode)
{
  switch (keycode)
  {
  case RAISE:
  case SYMBOL:
    return false;
  default:
    return true;
  }
}
