#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _SYMBOL 3
#define _MOUSE 4
#define _RAISE 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  SYMBOL,
  RAISE,
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
#define XXXXXXX KC_NO

#define CB_LALT ALT_T(KC_S)  //Alt on hold, S on tap
#define CB_LCTL CTL_T(KC_R)  //Ctrl on hold, R on tap
#define CB_LGUI GUI_T(KC_T)  //Gui on hold, T on tap

#define CB_RGUI GUI_T(KC_N)  //Gui on hold, N on tap
#define CB_RALT ALT_T(KC_E)  //Alt on hold, E on tap
#define CB_RCTL CTL_T(KC_I)  //Ctrl on hold, I on tap

#define CB_LMSE LT(_MOUSE, KC_A) //Mouse layer on hold, A on tap
#define CB_RMSE LT(_MOUSE, KC_O) //Mouse layer on hold, O on tap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTRL,KC_LGUI, KC_LALT, ADJUST,  SYMBOL,  KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

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
[_COLEMAK] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,     KC_P,    KC_G,    KC_J,    KC_L,     KC_U,    KC_Y,    KC_SCLN, KC_ESC, \
  KC_BSPC, CB_LMSE, CB_LCTL, CB_LALT,  CB_LGUI, KC_D,    KC_H,    CB_RGUI,  CB_RALT, CB_RCTL,    KC_O, ADJUST, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_K,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI,  SYMBOL,  KC_SPC,  KC_ENT,  RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Symbol|Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, SYMBOL,  KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

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
[_SYMBOL] = LAYOUT( \
  _______, KC_SLSH, KC_MINS,  KC_EQL, KC_EXLM,   KC_NO,   KC_NO, KC_AMPR, KC_ASTR, KC_PLUS, KC_BSLS, _______, \
  _______, KC_DQUO, KC_LBRC, KC_LCBR,   KC_AT, KC_LABK, KC_RABK, KC_UNDS, KC_RCBR, KC_RBRC, KC_QUOT, _______, \
  _______, KC_PERC, KC_HASH,  KC_DLR,  KC_GRV, KC_CIRC,   KC_NO, KC_PIPE, KC_TILD, KC_QUES, KC_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

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
[_MOUSE] = LAYOUT( \
  _______, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______, _______, KC_PGUP,   KC_UP, KC_PGDN, _______, _______, \
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, _______, \
  _______, _______, _______, _______, _______, _______, _______,  KC_DEL,  KC_INS, _______, _______, _______, \
  _______, _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

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
[_ADJUST] =  LAYOUT( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______,   RESET, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
        update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
