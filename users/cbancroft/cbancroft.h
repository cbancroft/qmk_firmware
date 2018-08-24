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

#ifndef USERSPACE
#define USERSPACE
#include "quantum.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum userspace_layers {
  _QWERTY = 0,
  _COLEMAK,
  _DVORAK,
  _SYMBOL,
  _MOUSE,
  _RAISE,
  _GAME,
  _ADJUST = 16,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  SYMBOL,
  RAISE,
  GAME,
  ADJUST,
};

// Blank template layer
/* Meta
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* [      ] = LAYOUT(                                                    \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),*/

// Fillers to make layering more clear
#define _______ KC_TRNS

#define XXX     KC_NO
#define XXXXXXX KC_NO

// Custom tap/hold rules.  These allow me to use Ctrl, Alt and GUI buttons on the home
// row to reduce RSI.  It still needs some tinkering with the timing as I am a fast typer and
// ocassionally they will trigger while doing normal typing.
#define CB_LALT ALT_T(KC_S)  //Alt on hold, S on tap
#define CB_LCTL CTL_T(KC_R)  //Ctrl on hold, R on tap
#define CB_LGUI GUI_T(KC_T)  //Gui on hold, T on tap

#define CB_RGUI GUI_T(KC_N)  //Gui on hold, N on tap
#define CB_RALT ALT_T(KC_E)  //Alt on hold, E on tap
#define CB_RCTL CTL_T(KC_I)  //Ctrl on hold, I on tap

//TODO: This is painful to use and should be swapped to another key
#define CB_LMSE LT(_MOUSE, KC_A) //Mouse layer on hold, A on tap
#define CB_RMSE LT(_MOUSE, KC_O) //Mouse layer on hold, O on tap

// Since our quirky block definitions are basically a list of comma separated
// arguments, we need a wrapper in order for these definitions to be
// expanded before being used as arguments to the LAYOUT_xxx macro.
// cribbed from @drashnas wonderful config
#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif

#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_planck_wrapper(...)           LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_letssplit_wrapper(...)        LAYOUT_ortho_4x12(__VA_ARGS__)

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]

// Blocks for each of the four major keyboard layouts
// Organized so we can quickly adapt and modify all of them
// at once, rather than for each keyboard, one at a time.
// And this allows for much cleaner blocks in the keymaps.
// For instance Tap/Hold for Control on all of the layouts

// NOTE: These are all the same length.  If you do a search/replace
//       then you need to add/remove underscores to keep the
//       lengths consistent.
#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       CB_LMSE, CB_LCTL, CB_LALT, CB_LGUI, KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    CB_RGUI, CB_RALT, CB_RCTL, KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______


#define _________________SYMBOL_L1_________________       KC_SLSH, KC_MINS, KC_EQL,  KC_EXLM, _______
#define _________________SYMBOL_L2_________________       KC_DQUO, KC_LBRC, KC_LCBR, KC_AT,   KC_LABK
#define _________________SYMBOL_L3_________________       KC_PERC, KC_HASH, KC_DLR,  KC_GRV,  KC_CIRC

#define _________________SYMBOL_R1_________________       _______, KC_AMPR, KC_ASTR, KC_PLUS, KC_BSLS
#define _________________SYMBOL_R2_________________       KC_RABK, KC_UNDS, KC_RCBR, KC_RBRC, KC_QUOT
#define _________________SYMBOL_R3_________________       _______, KC_PIPE, KC_TILD, KC_QUES, KC_SLSH


#define _________________MOUSE_L1__________________       _______, KC_WH_D, KC_MS_U, KC_WH_U, _______
#define _________________MOUSE_L2__________________       _______, KC_MS_L, KC_MS_D, KC_MS_R, _______
#define _________________MOUSE_L3__________________       ___________________BLANK___________________

#define _________________MOUSE_R1__________________       _______, KC_PGUP,   KC_UP, KC_PGDN, _______
#define _________________MOUSE_R2__________________       KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END
#define _________________MOUSE_R3__________________       _______,  KC_DEL,  KC_INS, _______, _______


#define _________________RAISE_L1__________________       _________________FUNC_LEFT_________________
#define _________________RAISE_L2__________________       ________________NUMBER_LEFT________________
#define _________________RAISE_L3__________________       ___________________BLANK___________________

#define _________________RAISE_R1__________________       _________________FUNC_RIGHT________________
#define _________________RAISE_R2__________________       ________________NUMBER_RIGHT_______________
#define _________________RAISE_R3__________________       ___________________BLANK___________________


#define _________________ADJUST_L1_________________       RESET,   _______, _______, _______, _______,
#define _________________ADJUST_L2_________________       _______, _______, AU_ON,   AU_OFF,  AG_NORM
#define _________________ADJUST_L3_________________       ___________________BLANK___________________

#define _________________ADJUST_R1_________________       _______, _______, _______, _______,   RESET
#define _________________ADJUST_R2_________________       AG_SWAP, QWERTY,  COLEMAK,  DVORAK, _______
#define _________________ADJUST_R3_________________       ___________________BLANK___________________


#define _________________GAMES_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________GAMES_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________GAMES_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________GAMES_R1_________________        _________________FUNC_LEFT_________________
#define _________________GAMES_R2_________________        ________________NUMBER_LEFT________________
#define _________________GAMES_R3_________________        ________________NUMBER_RIGHT_______________

// Blank template layer
/* Meta
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* [      ] = LAYOUT(                                                    \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),*/


/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |Adjust|Symbol|Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
#define QWERTY_ORTHO  \
  KC_ESC,   _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, \
  KC_TAB,   _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT, \
  KC_LSFT,  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_ENT , \
  KC_LCTRL, KC_LGUI, KC_LALT, ADJUST,  SYMBOL,  KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT


/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Tab  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |LMSE A|Ctrl R| Alt S| Win T|   D  |   H  | Win N| Alt E|Ctrl I|   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | ESC  |Symbol|Space |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
#define COLEMAK_ORTHO \
  KC_TAB,  _________________COLEMAK_L1________________, _________________COLEMAK_R1________________, KC_ESC, \
  KC_BSPC, _________________COLEMAK_L2________________, _________________COLEMAK_R2________________, ADJUST, \
  KC_LSPO, _________________COLEMAK_L3________________, _________________COLEMAK_R3________________, KC_RSPC, \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI,  SYMBOL,  KC_SPC,  KC_ENT,  RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT


/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |   /  |   -  |   =  |   !  |      |      |   &  |   *  |   +  |   \  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   "  |   [  |   {  |   @  |   <  |   >  |   _  |   }  |   ]  |   '  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   %  |   #  |   $  |   `  |   ^  |      |   |  |   ~  |   ?  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
#define SYMBOL_ORTHO \
  _______, _________________SYMBOL_L1_________________, _________________SYMBOL_R1_________________, _______, \
  _______, _________________SYMBOL_L2_________________, _________________SYMBOL_R2_________________, _______, \
  _______, _________________SYMBOL_L3_________________, _________________SYMBOL_R3_________________, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______


/* Mouse/Arrows                    .                    .
 * ,-----------------------------------------------------------------------------------.
 * |      |      |MwDown| MsUp | MwUp |      |      | PgUp |  Up  |PgDown|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |MsLeft|MsDown|MsRght|      | Home | Left | Down | Right| End  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  Del |  Ins |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |MsLclk|MsRclk|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
#define MOUSE_ORTHO \
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______, \
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______, \
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______, \
  _______, _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
#define RAISE_ORTHO \
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________,  KC_F11, \
  KC_DEL,  _________________RAISE_L2__________________, _________________RAISE_R2__________________,    KC_F12, \
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY

/* Adjust (Symbol+ Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
#define ADJUST_ORTHO \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______,   RESET, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,    GAME,  QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

/* Games
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |Adjust|Symbol|Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
#define GAMES_ORTHO  \
  KC_ESC,   _________________GAMES_L1_________________, _________________GAMES_R1_________________, KC_BSPC, \
  KC_TAB,   _________________GAMES_L2_________________, _________________GAMES_R2_________________, KC_QUOT, \
  KC_LSFT,  _________________GAMES_L3_________________, _________________GAMES_R3_________________, KC_ENT , \
  KC_LCTRL, KC_LGUI, KC_LALT, RAISE,  RAISE,  KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT

#endif // !USERSPACE
