// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum Layer {
    _ALPHA = 0,
    _LOWER = 1,
    _RAISE = 2,
    _ADJUST = 3,
    _GAME = 4,
    _GAMELOWER = 5,
    _ERGOL = 6,
    _DK = 7,
    _NAV = 8,
    _SYM = 9,
};

enum CustomKeycodes {
    M_EA = SAFE_RANGE,
    M_EG,
    M_EC,
    M_AG,
    M_AC,
    M_UG,
    M_UC,
    M_OC,
    M_IC,
    M_CC,
    M_APS,
    M_QTE,
    M_GRV,
    M_HAT,
    M_TLD,
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
#define S_PLS S(KC_EQL)
#define S_PIP S(KC_BSLS)
#define S_UDS S(KC_MINS)
#define S_LCB S(KC_LBRC)
#define S_RCB S(KC_RBRC)

const key_override_t Base_EKC_DK   = ko_make_with_layers(MOD_MASK_SHIFT, OSL(_DK), KC_EXLM, (1 << _ERGOL));
const key_override_t Base_EKC_MNS  = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_QUES, (1 << _ERGOL));
const key_override_t Base_EKC_DOT  = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLN, (1 << _ERGOL));
const key_override_t Base_EKC_COMM = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, (1 << _ERGOL));
const key_override_t DK_EKC_D      = ko_make_with_layers(MOD_MASK_SHIFT, KC_UNDS, KC_UNDS, (1 << _DK));
const key_override_t DK_EKC_L      = ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_LPRN, (1 << _DK));
const key_override_t DK_EKC_R      = ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_RPRN, (1 << _DK));

const key_override_t **key_overrides = (const key_override_t *[]){
	&Base_EKC_DK, &Base_EKC_MNS, &Base_EKC_DOT, &Base_EKC_COMM, &DK_EKC_D, &DK_EKC_L, &DK_EKC_R, NULL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_A,         KC_Z,              KC_E,                 KC_R,                KC_T,                               KC_Y,       KC_U,         KC_I,         KC_O,         KC_P,         KC_DEL,
        KC_TAB,  LGUI_T(KC_Q), LALT_T(KC_S),      LCTL_T(KC_D),         LSFT_T(KC_F),        KC_G,                               KC_H,       RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_M), KC_ENT,
        KC_NO,   KC_W,         LT(_ALPHA, KC_X),  LT(_ALPHA, KC_C),     LT(_ALPHA, KC_V),    KC_B,                               KC_N,       KC_SCLN,      KC_COMM,      KC_DOT,       KC_SLSH,      KC_NO,
                                                  MO(_LOWER),           KC_SPC,              KC_NO,                     KC_NO,   MO(_RAISE), KC_BSPC
    ),

    [_LOWER] = LAYOUT_split_3x6_3(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, S_DOL,   S_PLS,   S_LPR,   S_RPR,   S_AT,                               S_PIP,   KC_MINS, KC_EQL,  S_UDS,   S_STR,   _______,
        _______, S_BNG,   S_HSH,   S_LCB,   S_RCB,   M_TLD,                              S_AMP,   KC_LBRC, KC_RBRC, S_PCT,   M_HAT,   _______,
                                            _______, _______, _______,         _______,  _______, _______
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
        _______,  M_AG,       _______,    _______,    _______,    _______,                               M_UC,       M_UG,                   M_IC,       M_OC,       _______,                _______,
        _______,  KC_CAPS,    KC_BSLS,    M_GRV,      M_EA,       M_APS,                                 _______,    LT(_RAISE, KC_LEFT),    KC_DOWN,    KC_UP,      LT(_RAISE, KC_RIGHT),   _______,
        _______,  _______,    M_EC,       M_CC,       M_EG,       M_QTE,                                 _______,    _______,                _______,    _______,    _______,                _______,
                                                      _______,    _______,   _______,          _______,  _______,    _______
    ),

    [_ADJUST] = LAYOUT_split_3x6_3(
        _______, KC_F1,    KC_F2,     KC_F3,       KC_F4,      KC_F5,                         KC_F6,            KC_F7,      KC_F8,      KC_F9,      KC_F10,    _______,
        _______, KC_F11,   _______,   DF(_GAME),   DF(_ERGOL), _______,                       QK_BOOTLOADER,    _______,    _______,    _______,    KC_F12,    _______,
        _______, _______,  _______,   _______,     _______,    _______,                       _______,          _______,    _______,    _______,    _______,   _______,
                                                   _______,    _______,  _______,             _______,          _______,    _______
    ),

    [_GAME] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,       KC_T,                               KC_Y,       KC_U,         KC_I,         KC_O,         KC_P,         KC_DEL,
        KC_TAB,  KC_A,   KC_S,    KC_D,    KC_F,       KC_G,                               KC_H,       KC_J,         KC_K,         KC_L,         KC_M,         KC_ENT,
        KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_V,       KC_B,                               KC_N,       KC_SCLN,      KC_COMM,      KC_DOT,       KC_SLSH,      DF(_ALPHA),
                                           MO(_GAMELOWER), KC_SPC, KC_LSFT,          _______,   _______,    _______
    ),

    [_GAMELOWER] = LAYOUT_split_3x6_3(
        _______, KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                       _______, _______, _______, _______, _______, _______,
        _______, _______,   _______,   _______,   _______,   _______,                    _______, _______, _______, _______, _______, _______,
        _______, _______,   _______,   _______,   _______,   _______,                    _______, _______, _______, _______, _______, _______,
                                                  _______,   _______, _______, _______,  _______, _______
    ),

    [_ERGOL] = LAYOUT_split_3x6_3(
        KC_ESC,     KC_Q,           KC_C,           KC_O,           KC_P,           KC_W,                               KC_J,       KC_M,           KC_D,           OSL(_DK),       KC_Y,           KC_DEL,
        KC_TAB,     LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_E),   LSFT_T(KC_N),   KC_F,                               KC_L,       RSFT_T(KC_R),   RCTL_T(KC_T),   RALT_T(KC_I),   LGUI_T(KC_U),   KC_ENT,
        KC_NO,      KC_Z,           KC_X,           KC_MINS,        KC_V,           KC_B,                               KC_DOT,     KC_H,           KC_G,           KC_COMM,        KC_K,           DF(_ALPHA),
                                                                    LSFT_T(KC_ESC), LT(_NAV, KC_SPC), KC_NO,    KC_NO,  LT(_NAV, KC_BSPC), LT(_SYM, KC_ENT)
    ),

    [_DK] = LAYOUT_split_3x6_3(
        _______, M_AC,    M_CC,     _______,  M_OC,     _______,                                     _______,   _______, KC_UNDS,   KC_DQT,   M_UC,    _______,
        _______, M_AG,    M_EA,     M_EG,     M_EC,     _______,                                     KC_LPRN,   KC_RPRN, M_IC,      _______,  M_UG,    _______,
        _______, _______, _______,  _______,  _______,  _______,                                     _______,   _______, _______,   _______,  KC_DOT,  _______,
                                              _______, _______, _______,        _______, _______, _______
    ),
    
    [_NAV] = LAYOUT_split_3x6_3(
        _______, KC_TAB,    KC_HOME,   KC_UP,   KC_END,    KC_PGUP,                      KC_SLSH,   KC_7,  KC_8,  KC_9,   KC_NO,    _______,
        _______, KC_CAPS,   KC_LEFT,   KC_DOWN, KC_RIGHT,  KC_PGDN,                      KC_MINS,   KC_4,  KC_5,  KC_6,   KC_0,     _______,
        _______, KC_NO,     KC_VOLD,   KC_MPLY, KC_VOLU,   S(KC_TAB),                    KC_COMM,   KC_1,  KC_2,  KC_3,   KC_DOT,   _______,
                                                _______,   _______, _______,   _______,  _______, _______
    ),

    [_SYM] = LAYOUT_split_3x6_3(
        _______,  M_HAT,    KC_LABK,    KC_RABK,    KC_DLR,     KC_PERC,                               KC_AT,      KC_AMPR,     KC_ASTR,    M_APS,      M_GRV,    _______,
        _______,  KC_LCBR,  KC_LPRN,    KC_RPRN,    KC_RCBR,    KC_EQL,                                KC_BSLS,    KC_PLUS,     KC_MINS,    KC_SLSH,    M_QTE,    _______,
        _______,  M_TLD,    KC_LBRC,    KC_RBRC,    KC_UNDS,    KC_HASH,                               KC_PIPE,    KC_EXLM,     KC_SCLN,    KC_COLON,   KC_QUES,  _______,
                                                    _______,    _______,   _______,          _______,  _______,    _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }


#define MACRO_CHAR(MACRO, str)      case MACRO:                         \
                                        if (record->event.pressed) {    \
                                            SEND_STRING(str);           \
                                        }                               \
                                        break;                          \


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(_ALPHA, KC_X):
        if (!record->tap.count && record->event.pressed) {
            tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
            return false;
        }
        break;
    case LT(_ALPHA, KC_C):
        if (!record->tap.count && record->event.pressed) {
            tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
            return false;
        }
        break;
    case LT(_ALPHA, KC_V):
        if (!record->tap.count && record->event.pressed) {
            tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
            return false;
        }
        break;
    case LT(_RAISE, KC_LEFT):
        if (!record->tap.count && record->event.pressed) {
            tap_code(KC_HOME);
            return false;
        }
        break;
    case LT(_RAISE, KC_RIGHT):
        if (!record->tap.count && record->event.pressed) {
            tap_code(KC_END);
            return false;
        }
        break;
    MACRO_CHAR(M_EA, "'e")
    MACRO_CHAR(M_EG, "`e")
    MACRO_CHAR(M_EC, "^e")
    MACRO_CHAR(M_AG, "`a")
    MACRO_CHAR(M_AC, "^a")
    MACRO_CHAR(M_UG, "`u")
    MACRO_CHAR(M_UC, "^u")
    MACRO_CHAR(M_OC, "^o")
    MACRO_CHAR(M_IC, "^i")
    MACRO_CHAR(M_CC, "'c")
    MACRO_CHAR(M_APS, "' ")
    MACRO_CHAR(M_QTE, SS_LSFT("' "))
    MACRO_CHAR(M_GRV, "` ")
    MACRO_CHAR(M_HAT, "^ ")
    MACRO_CHAR(M_TLD, "~ ")
    }
    return true;
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ESC):
        case LT(_SYM, KC_ENT):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}