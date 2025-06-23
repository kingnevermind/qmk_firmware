/* Copyright 2019 ENDO Katsuhiro <ka2hiro@kagizaraya.jp>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "board.h"
#include "keymap_french.h"

enum layer_number {
    _BASE,      // 0
    _LOWER,     // 1
    _RAISE,     // 2
    _ADJUST,    // 3
    _FUNCTION,  // 4
    _ARROWS,    // 5
    _SUBLIME,   // 6
};



// // Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes { QWERTY = SAFE_RANGE, COLEMAK, DVORAK };

#define LOWER       MO(_LOWER)
#define RAISE       MO(_RAISE)
#define ADJUST      MO(_ADJUST)
#define FUNCTION    MO(_FUNCTION)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    // +-----------------------------------------------------------------------------------+
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+
    [_BASE] = LAYOUT(
        KC_ESC,        FR_Q,    FR_W,    LT(5,KC_F),        LT(6,KC_P),        KC_B,   KC_J,        KC_L,              KC_U,                 KC_Y,    FR_EACU, KC_BSPC,
        KC_TAB,        FR_A,    KC_R,    KC_S,              KC_T,              KC_G,   KC_H,        KC_N,              KC_E,                 KC_I,    KC_O,    KC_ENT,
        OSM(MOD_LSFT), FR_Z,    KC_X,    MT(MOD_LCTL,KC_C), MT(MOD_LSFT,KC_D), KC_V,   KC_K,        MT(MOD_RSFT,FR_M), MT(MOD_LCTL,FR_COMM), FR_DOT,  KC_UP,   FR_SCLN,
        FUNCTION,      KC_LCTL, KC_LALT, KC_LGUI,           LOWER,             KC_SPC, KC_SPC,      RAISE,             KC_DELETE,            KC_LEFT, KC_DOWN, KC_RGHT
    ),


    // +-----------------------------------------------------------------------------------+
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+
    [_LOWER] = LAYOUT(
        KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,  FR_SECT,    FR_DEG,     FR_DLR,     FR_EURO,    KC_NO,     KC_BSPC,
        KC_TAB,  FR_AT,   KC_NO,   KC_NO,   LCTL(FR_Z), KC_NO,  KC_NO,      FR_EXLM,    FR_QUES,    FR_HASH,    FR_BSLS,    KC_ENT,
        KC_LSFT, FR_DIAE, KC_NO,   KC_NO,   LCTL(KC_Y), KC_NO,  FR_MICR,    FR_TILD,    FR_AMPR,    FR_PIPE,    KC_UP,      FR_GRV,
        KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,      KC_SPC, KC_SPC,     RAISE,      KC_DELETE,  KC_LEFT,    KC_DOWN,    KC_RGHT
    ),


    // +-----------------------------------------------------------------------------------+
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+
    [_RAISE] = LAYOUT(
        KC_ESC,      FR_COLN, FR_QUOT,     FR_DQUO,        KC_KP_PLUS,  KC_NO,          KC_NO,        KC_KP_7,  KC_KP_8,    KC_KP_9,  FR_EGRV,   KC_BSPC,
        KC_TAB,      FR_AGRV, KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_DOT,   KC_EQUAL,       FR_UNDS,      KC_KP_4,  KC_KP_5,    KC_KP_6,  KC_KP_0,   KC_ENT,
        KC_CAPSLOCK, FR_CIRC, FR_UGRV,     FR_CCED,        KC_KP_SLASH, KC_NO,          KC_NO,        KC_KP_1,  KC_KP_2,    KC_KP_3,  KC_KP_DOT, FR_PERC,
        KC_NO,       KC_LCTL, KC_LALT,     KC_LGUI,        LOWER,       KC_SPC,         KC_SPC,       RAISE,    KC_DELETE,  KC_NO,    KC_NO,     KC_NO
    ),


    // +-----------------------------------------------------------------------------------+
    // | RST  |      |      |      | SCLK | NMLK |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+

    [_ADJUST] = LAYOUT(
          RESET, KC_NO, KC_NO, KC_NO, KC_NUMLOCK,  KC_SCROLLLOCK, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),


    // +-----------------------------------------------------------------------------------+
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+
    [_FUNCTION] = LAYOUT(
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),


    // +-----------------------------------------------------------------------------------+
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+
    [_ARROWS] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_PGUP,   KC_HOME,       KC_UP,        KC_END,          LSFT(KC_F10),     KC_BSPC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LSHIFT, KC_NO,   KC_PGDOWN, KC_LEFT,       KC_DOWN,      KC_RIGHT,        LCTL(LSFT(KC_T)), KC_ENT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT,   KC_NO,   KC_F2,     LCTL(KC_PGUP), KC_NO,        LCTL(KC_PGDOWN), LCTL(LSFT(KC_N)), LCTL(LSFT(FR_W)),
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_SPC,  KC_SPC,    KC_LCTRL,      KC_NO,        KC_NO,           KC_NO,            KC_NO
    ),


    // +-----------------------------------------------------------------------------------+
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+
    [_SUBLIME] = LAYOUT(
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

};




layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



bool led_update_user(led_t led_state) {
    board_set_led_by_index(0, LED_YELLOW, led_state.caps_lock);
    board_set_led_by_index(1, LED_YELLOW, led_state.scroll_lock);
    return false;
}
