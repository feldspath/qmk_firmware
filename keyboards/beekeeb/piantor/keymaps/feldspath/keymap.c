// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define RAISE

enum Layer {
    _ALPHA = 0,
    _LOWER = 1,
    _RAISE = 2,
    _ADJUST = 3,
};

enum CustomKeycodes {
    M_EA = SAFE_RANGE,
    M_EG,
    M_EC,
    M_AG,
    M_UG,
    M_UC,
    M_OC,
    M_CC,
    M_APS,
    M_QTE,
    M_GRV,
    M_HAT,
};

#define S_BNG S(KC_1)
#define S_AT S(KC_2)
#define S_HSH S(KC_3)
#define S_DOL S(KC_4)
#define S_PCT S(KC_5)
#define S_AMP S(KC_7)
#define S_STR S(KC_8)
#define S_LPR S(KC_9)
#define S_RPR S(KC_0)
#define S_TLD S(KC_GRV)
#define S_PLS S(KC_EQL)
#define S_PIP S(KC_BSLS)
#define S_UDS S(KC_MINS)
#define S_LCB S(KC_LBRC)
#define S_RCB S(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_ALPHA] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_A,         KC_Z,         KC_E,         KC_R,           KC_T,                               KC_Y,       KC_U,         KC_I,         KC_O,         KC_P,         KC_DEL,
        KC_TAB,  LGUI_T(KC_Q), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),   KC_G,                               KC_H,       RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_M), KC_ENT,
        KC_NO,   KC_W,         LT(0, KC_X),  LT(0, KC_C),  LT(0, KC_V),    KC_B,                               KC_N,       KC_SCLN,      KC_COMM,      KC_DOT,       KC_SLSH,      KC_NO,
                                                           MO(_LOWER),     KC_SPC,  KC_NO,             KC_NO,  MO(_RAISE), KC_BSPC
    ),

    [_LOWER] = LAYOUT_split_3x6_3(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, S_DOL,   S_PLS,   S_LPR,   S_RPR,   S_AT,                               S_PIP,   KC_MINS, KC_EQL,  S_UDS,   S_STR,   _______,
        _______, S_BNG,   S_HSH,   S_LCB,   S_RCB,   S_TLD,                              S_AMP,   KC_LBRC, KC_RBRC, S_PCT,   M_HAT,   _______,
                                            _______, _______, _______,         _______,  _______, _______
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
        _______,  M_AG,       _______,    _______,    _______,    _______,                               _______,    M_UG,       M_UC,    M_OC,       _______,    _______,
        _______,  _______,    _______,    M_GRV,      M_EA,       M_APS,                                 _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   _______,
        _______,  _______,    M_EC,       M_CC,       M_EG,       M_QTE,                                 _______,    _______,    _______,    _______,    _______,    _______,
                                                      _______,    _______,   _______,          _______,  _______,    _______
    ),

    [_ADJUST] = LAYOUT_split_3x6_3(
        _______, KC_F1,    KC_F2,     KC_F3,       KC_F4,      KC_F5,                         KC_F6,            KC_F7,      KC_F8,      KC_F9,      KC_F10,    _______,
        _______, KC_F11,   _______,   _______,     _______,    _______,                       QK_BOOTLOADER,    _______,    _______,    _______,    KC_F12,    _______,
        _______, _______,  _______,   _______,     _______,    _______,                       _______,          _______,    _______,    _______,    _______,   _______,
                                                   _______,    _______,  _______,             _______,          _______,    _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(0,KC_X):
          if (!record->tap.count && record->event.pressed) {
              tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
              return false;
          }
          return true;             // Return true for normal processing of tap keycode
    case LT(0,KC_C):
          if (!record->tap.count && record->event.pressed) {
              tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
              return false;
          }
          return true;             // Return true for normal processing of tap keycode
    case LT(0,KC_V):
          if (!record->tap.count && record->event.pressed) {
              tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
              return false;
          }
          return true;
    case M_EA:
        if (record->event.pressed) {
            SEND_STRING("'e");
        }
        break;
    case M_EG:
        if (record->event.pressed) {
            SEND_STRING("`e");
        }
        break;
    case M_EC:
        if (record->event.pressed) {
            SEND_STRING("^e");
        }
        break;
    case M_AG:
        if (record->event.pressed) {
            SEND_STRING("`a");
        }
        break;
    case M_UG:
        if (record->event.pressed) {
            SEND_STRING("`u");
        }
        break;
    case M_UC:
        if (record->event.pressed) {
            SEND_STRING("^u");
        }
        break;
    case M_OC:
        if (record->event.pressed) {
            SEND_STRING("^o");
        }
        break;
    case M_CC:
        if (record->event.pressed) {
            SEND_STRING("'c");
        }
        break;
    case M_APS:
        if (record->event.pressed) {
            SEND_STRING("' ");
        }
        break;
    case M_QTE:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT("' "));
        }
        break;
    case M_GRV:
        if (record->event.pressed) {
            SEND_STRING("` ");
        }
        break;
    case M_HAT:
        if (record->event.pressed) {
            SEND_STRING("^ ");
        }
        break;
    }
    
    return true;
};