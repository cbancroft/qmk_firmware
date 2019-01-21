#include "lets_split.h"
#include "cbancroft.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_letssplit_wrapper(QWERTY_ORTHO),
[_COLEMAK] = LAYOUT_letssplit_wrapper(COLEMAK_ORTHO),
[_SYMBOL] = LAYOUT_letssplit_wrapper(SYMBOL_ORTHO),
[_MOUSE] = LAYOUT_letssplit_wrapper(MOUSE_ORTHO),
[_RAISE] = LAYOUT_letssplit_wrapper(RAISE_ORTHO),
[_GAME] = LAYOUT_letssplit_wrapper(GAMES_ORTHO),
[_ADJUST] = LAYOUT_letssplit_wrapper(ADJUST_ORTHO),
};
