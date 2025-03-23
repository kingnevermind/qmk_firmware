/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

#include "keymap_french.h"

enum planck_layers {
    _BASE,      // 0
    _LOWER,     // 1
    _RAISE,     // 2
    _ADJUST,    // 3
    _FUNCTION,  // 4
    _ARROWS,    // 5
    _SUBLIME,   // 6
};


enum planck_keycodes {
  ST_MACRO_0 = SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_11,
  DANCE_12,
  DANCE_13,
  DANCE_14,
  DANCE_15,
  DANCE_16,
  DANCE_17,
  DANCE_18,
  DANCE_19,

};



#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // +-----------------------------------------------------------------------------------+
    // | ESC  |  Q   |  W   |  F   |  P   |  B   |  J   |  L   |  U   |  Y   |  É   | BSPC |
    // |-----------------------------------------------------------------------------------|
    // | TAB  |  A   |  R   |  S   |  T   |  G   |  H   |  N   |  E   |  I   |  O   | ENT  |
    // |-----------------------------------------------------------------------------------|
    // | LSFT |  Z   |  X   |  C   |  D   |  V   | *K*  |  M   |  ,   |  .   |  UP  | ;    |
    // |-----------------------------------------------------------------------------------|
    // | MO(4)| LCTL | LALT | LGUI | LOW  | SPC  | SPC  | RAIS | DEL  | LEFT | DOWN | RGHT |
    // +-----------------------------------------------------------------------------------+

    [_BASE] = LAYOUT_planck_grid(
        KC_ESC,        FR_Q,    FR_W,    LT(5,KC_F),        LT(6,KC_P),        KC_B,   KC_J,        KC_L,              KC_U,                 KC_Y,    FR_EACU, KC_BSPC,
        KC_TAB,        FR_A,    KC_R,    KC_S,              KC_T,              KC_G,   KC_H,        KC_N,              KC_E,                 KC_I,    KC_O,    KC_ENT,
        OSM(MOD_LSFT), FR_Z,    KC_X,    MT(MOD_LCTL,KC_C), MT(MOD_LSFT,KC_D), KC_V,   KC_K,        MT(MOD_RSFT,FR_M), MT(MOD_LCTL,FR_COMM), FR_DOT,  KC_UP,   FR_SCLN,
        MO(4),         KC_LCTL, KC_LALT, KC_LGUI,           LOWER,             KC_SPC, KC_SPC,      RAISE,             KC_DELETE,            KC_LEFT, KC_DOWN, KC_RGHT),



    // +-----------------------------------------------------------------------------------+
    // | ESC  |      |      | date | date |      |  §   |  °   |  $   |  €   |  É   | BSPC |
    // |-----------------------------------------------------------------------------------|
    // | TAB  |  @   |      |pastry|  ^Z  |      |  ±   |  !   |  ?   |  #   |  \   | ENT  |
    // |-----------------------------------------------------------------------------------|
    // | LSFT |  ¨   |      |  Ç   |  ^Y  |      |  µ   |  ~   |  &   |  |   |  UP  | GRV  |
    // |-----------------------------------------------------------------------------------|
    // |      | LCTL | LALT | LGUI | LOW  | SPC  | SPC  | RAIS | DEL  | LEFT | DOWN | RGHT |
    // +-----------------------------------------------------------------------------------+

    [_LOWER] = LAYOUT_planck_grid(
        KC_ESC,  KC_NO,   KC_NO,   ST_MACRO_0,  ST_MACRO_1, KC_NO,  FR_SECT,    FR_DEG,     FR_DLR,     FR_EURO,    ST_MACRO_2, KC_BSPC,
        KC_TAB,  FR_AT,   KC_NO,   ST_MACRO_3,  LCTL(FR_Z), KC_NO,  ST_MACRO_4, FR_EXLM,    FR_QUES,    FR_HASH,    FR_BSLS,    KC_ENT,
        KC_LSFT, FR_DIAE, KC_NO,   ST_MACRO_5,  LCTL(KC_Y), KC_NO,  FR_MICR,    FR_TILD,    FR_AMPR,    FR_PIPE,    KC_UP,      FR_GRV,
        KC_NO,   KC_LCTL, KC_LALT, KC_LGUI,     LOWER,      KC_SPC, KC_SPC,     RAISE,      KC_DELETE,  KC_LEFT,    KC_DOWN,    KC_RGHT),



    // +-----------------------------------------------------------------------------------+
    // | ESC  |  :   |  '   |  "   |  +   |      |      |  7  [E] 8  [F] 9   |  è   | BSPC |
    // |-----------------------------------------------------------------------------------|
    // | TAB  |  à   |  -   |  *   |  .   |  =   |  _   |  4  [C] 5  [D] 6   |  0   | ENT  |
    // |-----------------------------------------------------------------------------------|
    // | CAP  |  ^   |  ù   |  ç   |  /   | <{[( | )]}> |  1  [A] 2  [B] 3   |  .   |  %   |
    // |-----------------------------------------------------------------------------------|
    // |      | LCTL | LALT | LGUI | LOW  | SPC  | SPC  | RAIS | DEL  |      |      |      |
    // +-----------------------------------------------------------------------------------+

    [_RAISE] = LAYOUT_planck_grid(
        KC_ESC,      FR_COLN, FR_QUOT,     FR_DQUO,        KC_KP_PLUS,  KC_NO,          KC_NO,        KC_KP_7,  KC_KP_8,    KC_KP_9,  FR_EGRV,   KC_BSPC,
        KC_TAB,      FR_AGRV, KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_DOT,   KC_EQUAL,       FR_UNDS,      KC_KP_4,  KC_KP_5,    KC_KP_6,  KC_KP_0,   KC_ENT,
        KC_CAPSLOCK, FR_CIRC, FR_UGRV,     FR_CCED,        KC_KP_SLASH, TD(DANCE_2),    TD(DANCE_3),  KC_KP_1,  KC_KP_2,    KC_KP_3,  KC_KP_DOT, FR_PERC,
        KC_NO,       KC_LCTL, KC_LALT,     KC_LGUI,        LOWER,       KC_SPC,         KC_SPC,       RAISE,    KC_DELETE,  KC_NO,    KC_NO,     KC_NO),



    // +-----------------------------------------------------------------------------------+
    // | RST  |      | SCLK | NMLK |      |      |      |RGBVA+|RGBHU+|RGBSA+|RGBSP+|BRTNS+|
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |RGBMOD|RGBVA-|RGBHU-|RGBSA-|RGBSP-|BRTNS-|
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      | LED  |RGBTOG|      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+

    [_ADJUST] = LAYOUT_planck_grid(
          RESET, KC_NO, KC_SCROLLLOCK, KC_NUMLOCK, KC_NO, KC_NO, KC_NO,     RGB_VAI,   RGB_HUI, RGB_SAI, RGB_SPI, KC_BRIGHTNESS_UP,
          KC_NO, KC_NO, KC_NO,         KC_NO,      KC_NO, KC_NO, RGB_MOD,   RGB_VAD,   RGB_HUD, RGB_SAD, RGB_SPD, KC_BRIGHTNESS_DOWN,
          KC_NO, KC_NO, KC_NO,         KC_NO,      KC_NO, KC_NO, KC_NO,     RGB_TOG,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
          KC_NO, KC_NO, KC_NO,         KC_NO,      KC_NO, KC_NO, KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO),



    // +-----------------------------------------------------------------------------------+
    // |      |  F7  |  F8  |  F9  | F12  |      |      |      |      |      |      | PSCR |
    // |-----------------------------------------------------------------------------------|
    // |      |  F4  |  F5  |  F6  | F11  |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // | LSFT |  F1  |  F2  |  F3  | F10  |      |      |      |      | PLAY | VOL+ | MUTE |
    // |-----------------------------------------------------------------------------------|
    // |      | LCTL | LALT | LGUI |      |      |      |      |      |  <<  | VOL- |  >>  |
    // +-----------------------------------------------------------------------------------+

    [_FUNCTION] = LAYOUT_planck_grid(
        KC_NO,   KC_F7,   KC_F8,   KC_F9, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,             KC_PSCREEN,
        KC_NO,   KC_F4,   KC_F5,   KC_F6, KC_F11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,             KC_NO,
        KC_LSFT, KC_F1,   KC_F2,   KC_F3, KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_VOL_UP,   KC_AUDIO_MUTE,
        KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK),



    // +-----------------------------------------------------------------------------------+
    // |      |      |      |      |      |      | PGUP | HOME |  UP  | END  | ^F10 | BSPC |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      | LSFT |      | PGDW | LEFT | DOWN | RGHT | !^T  | ENT  |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      | ALT  |      |  F2  |!PGUP |      |!PGDW | !^N  | !^W  |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      | SPC  | SPC  | LCTL | SUBL |      |      |      |
    // +-----------------------------------------------------------------------------------+

    [_ARROWS] = LAYOUT_planck_grid(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_PGUP,   KC_HOME,       KC_UP,        KC_END,          LSFT(KC_F10),     KC_BSPC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LSHIFT, KC_NO,   KC_PGDOWN, KC_LEFT,       KC_DOWN,      KC_RIGHT,        LCTL(LSFT(KC_T)), KC_ENT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT,   KC_NO,   KC_F2,     LCTL(KC_PGUP), KC_NO,        LCTL(KC_PGDOWN), LCTL(LSFT(KC_N)), LCTL(LSFT(FR_W)),
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_SPC,  KC_SPC,    KC_LCTRL,      TD(DANCE_1),  KC_NO,           KC_NO,            KC_NO),



    // +-----------------------------------------------------------------------------------+
    // |      |      |      |      |      |      |      | +!1  | +!2  | +!3  |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |fold 1|fold 2|fold 3|fold 0|      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+

    [_SUBLIME] = LAYOUT_planck_grid(
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(LALT(KC_KP_1)), LSFT(LALT(KC_KP_2)), LSFT(LALT(KC_KP_3)),   KC_NO,          KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, ST_MACRO_8,          ST_MACRO_9,          ST_MACRO_10,           ST_MACRO_11,    KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,               KC_NO,                 KC_NO,          KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,               KC_NO,                 KC_NO,          KC_NO),
};




// /////////////////////////////////////////////////////////////////////////////
// COMBOS
// /////////////////////////////////////////////////////////////////////////////



const uint16_t PROGMEM combo0[] = { KC_V, KC_K, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_KP_1, KC_KP_2, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_KP_4, KC_KP_5, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_KP_2, KC_KP_3, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_KP_5, KC_KP_6, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_KP_7, KC_KP_8, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_KP_8, KC_KP_9, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LALT(LSFT(FR_SCLN))),
    COMBO(combo1, LSFT(FR_A)),
    COMBO(combo2, LSFT(KC_C)),
    COMBO(combo3, LSFT(KC_B)),
    COMBO(combo4, LSFT(KC_D)),
    COMBO(combo5, LSFT(KC_E)),
    COMBO(combo6, LSFT(KC_F)),
};



// #ifdef AUDIO_ENABLE
//   float plover_song[][2]     = SONG(PLOVER_SOUND);
//   float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
// #endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}




// /////////////////////////////////////////////////////////////////////////////
// MACROS
// /////////////////////////////////////////////////////////////////////////////



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_SCOLON) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_H) SS_DELAY(100) SS_TAP(X_SCOLON));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_SCOLON) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_8) SS_DELAY(100) SS_TAP(X_8));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_4) ));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_N))) SS_DELAY(100) SS_TAP(X_KP_0)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_1) ));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_8) ));

    }
    break;
    // case ST_MACRO_6:
    // if (record->event.pressed) {
    //   SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_ENTER));

    // }
    // break;
    // case ST_MACRO_7:
    // if (record->event.pressed) {
    //   SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_ENTER));

    // }
    // break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_KP_1)));

    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_KP_2)));

    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_KP_3)));

    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_KP_0)));

    }
    break;
  }
  return true;
}




// /////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////



typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};


static tap dance_state[17];
uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


#if 0
// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 0 : Doule K
// /////////////////////////////////////////////////////////////////////////////


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case DOUBLE_TAP: register_code16(LALT(LSFT(FR_SCLN))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_TAP: unregister_code16(LALT(LSFT(FR_SCLN))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[0].step = 0;
}
#endif


// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 1 :
// /////////////////////////////////////////////////////////////////////////////



void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_U));
        tap_code16(LCTL(KC_U));
        tap_code16(LCTL(KC_U));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_U));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_U)); break;
        case SINGLE_HOLD: register_code16(KC_ENTER); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_U))); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LSFT(KC_U)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_U)); register_code16(LCTL(KC_U));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_U)); break;
        case SINGLE_HOLD: unregister_code16(KC_ENTER); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_U))); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LSFT(KC_U)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_U)); break;
    }
    dance_state[1].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 2 : Opening Brackets
// /////////////////////////////////////////////////////////////////////////////



void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_LPRN);
        tap_code16(FR_LPRN);
        tap_code16(FR_LPRN);
    }
    if(state->count > 3) {
        tap_code16(FR_LPRN);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(FR_LPRN); break;
        case SINGLE_HOLD: register_code16(FR_LABK); break;
        case DOUBLE_TAP: register_code16(RALT(KC_5)); break;
        case DOUBLE_HOLD: register_code16(RALT(KC_4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_LPRN); register_code16(FR_LPRN);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(FR_LPRN); break;
        case SINGLE_HOLD: unregister_code16(FR_LABK); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_5)); break;
        case DOUBLE_HOLD: unregister_code16(RALT(KC_4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_LPRN); break;
    }
    dance_state[2].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 3 : Closing Brackets
// /////////////////////////////////////////////////////////////////////////////



void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_RPRN);
        tap_code16(FR_RPRN);
        tap_code16(FR_RPRN);
    }
    if(state->count > 3) {
        tap_code16(FR_RPRN);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(FR_RPRN); break;
        case SINGLE_HOLD: register_code16(RSFT(FR_RABK)); break;
        case DOUBLE_TAP: register_code16(RALT(KC_MINUS)); break;
        case DOUBLE_HOLD: register_code16(RALT(KC_EQUAL)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_RPRN); register_code16(FR_RPRN);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(FR_RPRN); break;
        case SINGLE_HOLD: unregister_code16(RSFT(FR_RABK)); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_MINUS)); break;
        case DOUBLE_HOLD: unregister_code16(RALT(KC_EQUAL)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_RPRN); break;
    }
    dance_state[3].step = 0;
}


#if 0
// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 11 : 1 & A
// /////////////////////////////////////////////////////////////////////////////



void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_1);
        tap_code16(KC_KP_1);
        tap_code16(KC_KP_1);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_1);
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_KP_1); break;
        case SINGLE_HOLD: register_code16(LSFT(FR_A)); break;
        case DOUBLE_TAP: register_code16(KC_KP_1); register_code16(KC_KP_1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_1); register_code16(KC_KP_1);
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_1); break;
        case SINGLE_HOLD: unregister_code16(LSFT(FR_A)); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_1); break;
    }
    dance_state[11].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 12 : 2 & B
// /////////////////////////////////////////////////////////////////////////////



void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_2);
        tap_code16(KC_KP_2);
        tap_code16(KC_KP_2);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_2);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_KP_2); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_B)); break;
        case DOUBLE_TAP: register_code16(KC_KP_2); register_code16(KC_KP_2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_2); register_code16(KC_KP_2);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_2); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_B)); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_2); break;
    }
    dance_state[12].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 16 : 6 & C
// /////////////////////////////////////////////////////////////////////////////



void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_3);
        tap_code16(KC_KP_3);
        tap_code16(KC_KP_3);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_3);
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_KP_3); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_C)); break;
        case DOUBLE_TAP: register_code16(KC_KP_3); register_code16(KC_KP_3); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_3); register_code16(KC_KP_3);
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_3); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_C)); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_3); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_3); break;
    }
    dance_state[13].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 14 : 4 & D
// /////////////////////////////////////////////////////////////////////////////



void on_dance_14(qk_tap_dance_state_t *state, void *user_data);
void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_14(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_4);
        tap_code16(KC_KP_4);
        tap_code16(KC_KP_4);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_4);
    }
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_KP_4); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_D)); break;
        case DOUBLE_TAP: register_code16(KC_KP_4); register_code16(KC_KP_4); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_4); register_code16(KC_KP_4);
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_4); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_D)); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_4); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_4); break;
    }
    dance_state[14].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 15 : 5 & E
// /////////////////////////////////////////////////////////////////////////////



void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_5);
        tap_code16(KC_KP_5);
        tap_code16(KC_KP_5);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_5);
    }
}

void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_KP_5); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_E)); break;
        case DOUBLE_TAP: register_code16(KC_KP_5); register_code16(KC_KP_5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_5); register_code16(KC_KP_5);
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_5); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_E)); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_5); break;
    }
    dance_state[15].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 16 : 6 & F
// /////////////////////////////////////////////////////////////////////////////



void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_6);
        tap_code16(KC_KP_6);
        tap_code16(KC_KP_6);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_6);
    }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_KP_6); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_F)); break;
        case DOUBLE_TAP: register_code16(KC_KP_6); register_code16(KC_KP_6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_6); register_code16(KC_KP_6);
    }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_6); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_F)); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_6); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_6); break;
    }
    dance_state[16].step = 0;
}
#endif


// /////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////



qk_tap_dance_action_t tap_dance_actions[] = {
        // [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        // [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        // [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        // [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        // [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        // [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        // [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        // [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
#if 0
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
#endif
};






