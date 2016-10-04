#include "atomic.h"
#include "action_layer.h"

// Fillers to make layering more clear
#define CTGRV   (LCTL(KC_GRV))
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

#define LAYER_BASE       0
#define LAYER_FUNC       1
#define LAYER_UHHH       2

enum {
  CT_E = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [LAYER_BASE] = { /* QWERTY
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | XXXXXX . BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * | FN0    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | ENTER . XXXXXX  | PG UP  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSHIFT . XXXXXX | UP     | PG DN  |
 * |-----------------------------------------------------------------------------------------+--------+-----------------+--------+--------|
 * | LCTRL    | LGUI    | LALT     |                  XXXXXX . SPACE                         | RALT   | CTRL+`  | LEFT  | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------' */
  { TD(CT_E),KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL   },
  { KC_FN0,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  XXXXXXX, KC_PGUP  },
  { KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, XXXXXXX, KC_UP,   KC_PGDN  },
  { KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, CTGRV,   KC_LEFT, KC_DOWN, KC_RGHT  },
 },

 [LAYER_FUNC] = { /* function
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * | CTRL+` | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX . BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        | UP     |        |        |        |        |        |        |        |        |        |        | PAUSE  | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * |        |  LEFT  | DOWN   | RIGHT  |        |        |        |        |        |        |        |        |        . XXXXXX | WHEEL+ |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * |        |        |        |        |        |        |        |        | VOL-   | VOL=   | PLAY   | RSHIFT . XXXXXX | MOUS U | WHEEL- |
 * |-----------------------------------------------------------------------------------------+--------+-----------------+--------+--------|
 * |          |         | LALT     |                  XXXXXX . SPACE                         |        |        | MOUS L | MOUS D | MOUS R |
 * '--------------------------------------------------------------------------------------------------------------------------------------' */
  { CTGRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_BSPC },
  { _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_PSCR },
  { _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_WH_U },
  { _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY, _______, XXXXXXX, KC_MS_U, KC_WH_D },
  { _______, _______, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R },
 },
 
 [LAYER_UHHH] = { /* UHHH
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * | CTRL+` | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX . BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        | PAUSE  | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        . XXXXXX | WHEEL+ |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * |        |        |        |        |        |        |        |        | VOL-   | VOL=   | PLAY   | RSHIFT . XXXXXX | MOUS U | WHEEL- |
 * |-----------------------------------------------------------------------------------------+--------+-----------------+--------+--------|
 * |          |         | LALT     |                  XXXXXX . SPACE                         |  FN    |        | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------' */
  { CTGRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_BSPC },
  { _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_PSCR },
  { _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_WH_U },
  { _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY, _______, XXXXXXX, KC_MS_U, KC_WH_D },
  { _______, _______, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R },
 }
};


void CT_CONEMU (qk_tap_dance_state_t *state) {
  if (state->count == 1) {         
    register_code (KC_ESC);      //define single tap here
    unregister_code (KC_ESC);
  } else {    
    register_code (KC_LCTL);      //define double tap here
    register_code (KC_GRV);
    unregister_code (KC_GRV);
    unregister_code (KC_LCTL);
    reset_tap_dance (state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_E] = ACTION_TAP_DANCE_FN(CT_CONEMU)
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_LCTL),
    [1] = ACTION_LAYER_MOMENTARY(1),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {
      case 0:
        return MACRODOWN(TYPE(KC_T), END);
      break;
    } 
    return MACRO_NONE;
};