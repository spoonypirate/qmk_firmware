#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define FN1  1 // media layer

#define CAPS_CTL CTL_T(KC_CAPS)  // Caps on tap, Ctrl on hold.
#define UNDO     LCTL(KC_Z)      // C-z UNDO
#define CUT      LCTL(KC_X)      // C-x Cut
#define COPY     LCTL(KC_C)      // C-c Copy
#define PASTE    LCTL(KC_V)      // C-v Paste
#define ZM_NRM   LCTL(KC_0)      // C-0 Zoom Normal
#define ZM_OUT   LCTL(KC_MINS)   // C-- Zoom Out
#define ZM_IN    LCTL(KC_PLUS)   // C-+ Zoom In
#define EM_UNDO  LCTL(KC_UNDS)   // C-_ Emacs Undo

#define _MOB  1 // Mobile#
#define _CUS1 2 // Custom macro 1
#define _CUS2 3 // Custom macro 2
enum {
  CT_Z = 0,
  CT_X,
  CT_C,
  CT_V
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | ESC  |           |   6  |   7  |   8  |   9  |   0  |   -  |   =    |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Fwd  |           | Back |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  '     |
 * |--------+------+------+------+------+------| HYPR |           | MEH  |------+------+------+------+------+--------|
 * | LS/PO  |Z/UNDO|X/CUT |C/CPY |V/PST |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  RS/PC |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Esc | LGui | Alt  | Alt  |                                       | Left |  Dn  |  Up  | Right|  Fn  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Copy |  (   |       |  APP | Paste|
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      | HOME |       | PGUP |      |      |
 *                                 |Space | Del  |------|       |------| Enter|BSpace|
 *                                 |      |      |  END |       | PGDN |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [BASE] = KEYMAP( 
	// Left hand
	KC_GRV,   KC_1,    KC_2,    KC_3,     KC_4,     KC_5,    KC_ESC,
	KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,    KC_WBAK,
	KC_LCTL,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,
	KC_LSPO,  TD(CT_Z),TD(CT_X),TD(CT_C), TD(CT_V), KC_B,    ALL_T(KC_NO),
	KC_LCTL,  KC_ESC,  KC_LGUI, KC_LALT,  KC_LALT,
	KC_LBRC,  KC_LCBR,
	KC_HOME,
	KC_SPC,   KC_BSPC,  KC_END, 
	// Right hand
	KC_6,           KC_7,    KC,      KC_9,     KC_0,     KC_MINS, KC_EQL,
	KC_WFWD,        KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSLS,
	KC_H,           KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,
	MEH_T(KC_NO),   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSPC,
	KC_LEFT,        KC_DOWN, KC_UP,   KC_RIGHT, MO(FN1),
	ALT_T(KC_APP),  KC_RBRC,
	KC_PGUP,
	KC_RBRC,  KC_ENT,  KC_SPC
	),
	/* Keymap 1: Fn Keys, media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | BSpace |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |play/ps |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | LClk | MClk | RClk |      |      |           |      |mobil#|      |mac1  |mac2  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Teensy|      | ZmNrm| ZmOut| ZmIn |                                       | Undo |VolDn |VolUp | Mute |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// FN1 Layer
    [FN1] = KEYMAP(
	// Left hand
	KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, ZM_NRM,  ZM_OUT,  ZM_IN,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	RESET,   KC_TRNS, KC_TRNS,
	// Right hand
	KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
	KC_TRNS, M(_MOB), KC_TRNS, M(_CUS1),M(_CUS2),KC_TRNS, KC_TRNS,
	EM_UNDO, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS
	),
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[CT_Z] = ACTION_TAP_DANCE_DOUBLE(KC_Z, UNDO),
	[CT_X] = ACTION_TAP_DANCE_DOUBLE(KC_X, CUT),
	[CT_C] = ACTION_TAP_DANCE_DOUBLE(KC_C, COPY),
	[CT_V] = ACTION_TAP_DANCE_DOUBLE(KC_V, PASTE)  
};
const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
    case _MOB: // Your mobile# here.
	return MACRODOWN(T(5), T(7), T(1), T(MINS),
			 T(2), T(4), T(9), T(MINS),
			 T(1), T(3), T(3), T(7),
			 END);
    case _CUS1: // Your custom macro 1
	return MACRODOWN(T(E), T(M), T(A), T(C), T(S), T(SPC), END);
    case _CUS2: // Your custom macro 2
	return MACRODOWN(T(L), T(S), T(SPC), T(MINS), T(A), T(L), T(ENT), END);
    };
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
	// TODO: Make this relevant to the ErgoDox EZ.
    case 1:
	ergodox_right_led_1_on();
	break;
    case 2:
	ergodox_right_led_2_on();
	break;
    default:
	// none
	break;
    }

};
