#include "xd60.h"
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  KEYMAP(
      KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, XXXXXXX,    \
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,    \
      F(0),      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX,          KC_ENT,     \
      KC_LSFT,   XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSFT, XXXXXXX,    \
      KC_LCTL,   KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, XXXXXXX, KC_APP,  KC_RCTL),

  // 1: Function Layer
  KEYMAP(
      KC_GESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  XXXXXXX,    \
      KC_DEL,    KC_WH_U, KC_UP,   KC_WH_D, RESET,   KC_HOME, KC_CALC, KC_BTN1, KC_UP,   KC_BTN2, KC_PAUS, KC_HOME, KC_END,           KC_PSCR,    \
      F(0),      KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  BL_TOGG, BL_STEP, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN, XXXXXXX,          KC_ENT,     \
      KC_LSFT,   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, KC_INS,  KC_DEL,  XXXXXXX, KC_RSFT, XXXXXXX,    \
      KC_LCTL,   KC_LGUI, KC_LALT,                            KC_SPC,                             KC_CAPS, KC_RGUI, XXXXXXX, KC_APP,  KC_RCTL),
};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn layer
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
