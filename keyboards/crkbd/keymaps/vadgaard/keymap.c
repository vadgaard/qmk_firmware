/* Copyright 2026 Lars Husted Vadgaard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 */

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _VIM,
    _ADJUST,
};

#define ESC_CTL LCTL_T(KC_ESC)
#define F_VIM   LT(_VIM, KC_F)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |------.  ,------|   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------| Ctrl |  |  Up  |------+------+------+------+------+------|
 * |EscCtl|   A  |   S  |   D  | F/Vim|   G  |------|  |------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|  Gui |  | Down |------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |------'  `------|   N  |   M  |   ,  |   .  |   /  |Shift |
 * `-----------------------------------------'                `-----------------------------------------'
 *                             ,------+------+------.  ,------+------+------.
 *                             |  Alt |Lower |Space |  |Enter |Raise |  Alt |
 *                             `--------------------'  `--------------------'
 */
[_BASE] = LAYOUT_split_3x6_3_ex2(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LCTL, KC_UP,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    ESC_CTL, KC_A,    KC_S,    KC_D,    F_VIM,   KC_G,    KC_LGUI, KC_DOWN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                        KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_RALT
),

/* Lower
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |      | Pscr |      | Ins  |      |      |------.  ,------|      |   {  |   }  |   ~  |   `  | Del  |
 * |------+------+------+------+------+------|      |  |      |------+------+------+------+------+------|
 * | Caps |      |      | PgUp | PgDn |      |------|  |------| Home |   (  |   )  |   -  |   =  |  \  |
 * |------+------+------+------+------+------|      |  |      |------+------+------+------+------+------|
 * |      |      |      | Menu |      |      |------'  `------| End  |   [  |   ]  |   _  |   +  |  |   |
 * `-----------------------------------------'                `-----------------------------------------'
 *                             ,------+------+------.  ,------+------+------.
 *                             |      |Lower |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 */
[_LOWER] = LAYOUT_split_3x6_3_ex2(
    XXXXXXX, KC_PSCR, XXXXXXX, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_TILD, KC_GRV,  KC_DEL,
    KC_CAPS, XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_BSLS,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_APP,  XXXXXXX, XXXXXXX,                   KC_END,  KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_PIPE,
                                        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |------.  ,------|   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|      |  |      |------+------+------+------+------+------|
 * | Caps |   !  |   @  |   #  |   $  |   %  |------|  |------|   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|      |  |      |------+------+------+------+------+------|
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |------'  `------|  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * `-----------------------------------------'                `-----------------------------------------'
 *                             ,------+------+------.  ,------+------+------.
 *                             |      |      |      |  |      |Raise |      |
 *                             `--------------------'  `--------------------'
 */
[_RAISE] = LAYOUT_split_3x6_3_ex2(
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_CAPS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX
),

/* Vim
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |      |      |      |      |      |      |------.  ,------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|      |  |      |------+------+------+------+------+------|
 * |      |      |      |      | Vim  |      |------|  |------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|      |  |      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |------'  `------|      |      |      |      |      |      |
 * `-----------------------------------------'                `-----------------------------------------'
 *                             ,------+------+------.  ,------+------+------.
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 */
[_VIM] = LAYOUT_split_3x6_3_ex2(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Boot |      |      |      |      |      |------.  ,------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|      |  |      |------+------+------+------+------+------|
 * |RGBtog| Hue+ | Sat+ | Val+ |      |      |------|  |------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|      |  |      |------+------+------+------+------+------|
 * |RGBmod| Hue- | Sat- | Val- |      |      |------'  `------|      |      |      |      |      |      |
 * `-----------------------------------------'                `-----------------------------------------'
 *                             ,------+------+------.  ,------+------+------.
 *                             |      |Lower |      |  |      |Raise |      |
 *                             `--------------------'  `--------------------'
 */
[_ADJUST] = LAYOUT_split_3x6_3_ex2(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
    [_LOWER]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
    [_VIM]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
};
#endif
