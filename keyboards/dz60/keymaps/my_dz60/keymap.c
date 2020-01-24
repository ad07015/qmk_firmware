#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define XXXXXXX KC_NO

typedef struct {
  bool is_press_action;
  int state;
} tap;

//Define a type for as many tap dance states as you need
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3
};

enum {
  CAPS_LAYR = 0     // Our custom tap dance key; add any other tap dance keys to this enum 
};

//Declare the functions to be used with your tap dance key(s)

//Function associated with all tap dances
int cur_dance (qk_tap_dance_state_t *state);

//Functions associated with individual tap dances
void ql_finished (qk_tap_dance_state_t *state, void *user_data);
void ql_reset (qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    LAYOUT_60_ansi(
        KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,       KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,       KC_RBRC, KC_BSLS,
        MO(1),          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                KC_RSFT,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             MO(2),   TD(CAPS_LAYR), KC_APP,  KC_RCTL),

    LAYOUT_60_ansi(
        KC_GRV,         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,        KC_F12,  KC_DEL,
        _______,        KC_WH_U, KC_UP,   KC_WH_D, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_PAUS, KC_HOME,       KC_END,  KC_PSCR,  
        _______,        KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP, KC_PGDN,                _______,
        _______,                 _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, _______, KC_INS,  KC_DEL,                 _______,
        _______,        _______, _______,                            _______,                            _______, _______,       _______, _______),

    LAYOUT_60_ansi(
        KC_GRV,         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,        KC_F12,  KC_DEL,
        _______,        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PAUS, KC_HOME,       KC_END,  RESET,
        _______,        RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, _______, KC_PGUP, KC_PGDN,                _______,
        _______,                 _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, BL_BRTG, _______, KC_INS,  KC_DEL,                 _______,
        _______,        _______,          _______,                   _______,                            _______, _______,       _______, _______)
};

//Determine the current tap dance state
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else return 8;
}

//Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void ql_finished (qk_tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP: 
      tap_code(KC_QUOT); 
      break;
    case SINGLE_HOLD: 
      layer_on(_MY_LAYER); 
      break;
    case DOUBLE_TAP: 
      //check to see if the layer is already set
      if (layer_state_is(_MY_LAYER)) {
        //if already set, then switch it off
        layer_off(_MY_LAYER);
      } else { 
        //if not already set, then switch the layer on
        layer_on(_MY_LAYER);
      }
      break;
  }
}

void ql_reset (qk_tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (ql_tap_state.state==SINGLE_HOLD) {
    layer_off(_MY_LAYER);
  }
  ql_tap_state.state = 0;
}

//Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
  [CAPS_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275)
>>>>>>> Stashed changes
};