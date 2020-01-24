#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_60_ansi(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             MO(2),   KC_CAPS, KC_APP,  KC_RCTL),

    LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_WH_U, KC_UP,   KC_WH_D, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_PAUS, KC_HOME, KC_END,  KC_PSCR,  
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP, KC_PGDN,          _______,
        _______,          _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, _______, KC_INS,  KC_DEL,           _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______),

    LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PAUS, KC_HOME, KC_END,  RESET,
        _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, _______, KC_PGUP, KC_PGDN,          _______,
        _______,          _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, BL_BRTG, _______, KC_INS,  KC_DEL,           _______,
        _______, _______,          _______,                   _______,                            _______, _______, _______, _______)
};