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


enum macro_keycodes {
    ST_MACRO_100 = SAFE_RANGE,      // macro autohotkey insert date & time
    ST_MACRO_101,                   // macro autohotkey insert date
    ST_MACRO_102,                   // insert alt code for É
    ST_MACRO_103,                   // macro sublime pastry
    ST_MACRO_104,                   // insert alt code ±
    ST_MACRO_105,                   // insert alt code Ç
    ST_MACRO_600,                   // macro sublime fold level 1
    ST_MACRO_601,                   // macro sublime fold level 2
    ST_MACRO_602,                   // macro sublime fold level 3
    ST_MACRO_603,                   // macro sublime fold level 0
};


enum tap_dance_codes {
  DANCE_200,
  DANCE_201,
  DANCE_500,
};


#define LOWER       MO(_LOWER)
#define RAISE       MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

    // +-----------------------------------------+      +-----------------------------------------+
    // | ESC  |  Q   |  W   |  F   |  P   |  B   |      |  J   |  L   |  U   |  Y   |  É   | BSPC |
    // |------------------------------------------      ------------------------------------------|
    // | TAB  |  A   |  R   |  S   |  T   |  G   |      |  H   |  N       |  E   |  I   |  O   | ENT  |
    // |------------------------------------------      ------------------------------------------|
    // | LSFT |  Z   |  X   |  C   |  D   |  V   |      |  K   |  M   |  ,   |  .   |  UP  |  ;   |
    // |------------------------------------------      ------------------------------------------|
    // | FUNC | LCTL | LALT | LGUI | LOW  | SPC  |      | SPC  | RAIS | DEL  | LEFT | DOWN | RGHT |
    // +-----------------------------------------+      +-----------------------------------------+

    [_BASE] = LAYOUT(
        KC_ESC,        FR_Q,    FR_W,    LT(_ARROWS,KC_F),        LT(_SUBLIME,KC_P),    KC_B,   KC_J,        KC_L,              KC_U,                 KC_Y,    FR_EACU, KC_BSPC,
        KC_TAB,        FR_A,    KC_R,    KC_S,                    KC_T,                 KC_G,   KC_H,        KC_N,              KC_E,                 KC_I,    KC_O,    KC_ENT,
        OSM(MOD_LSFT), FR_Z,    KC_X,    MT(MOD_LCTL,KC_C),       MT(MOD_LSFT,KC_D),    KC_V,   KC_K,        MT(MOD_RSFT,FR_M), MT(MOD_LCTL,FR_COMM), FR_DOT,  KC_UP,   FR_SCLN,
        MO(_FUNCTION), KC_LCTL, KC_LALT, KC_LGUI,                 MO(_LOWER),           KC_SPC, KC_SPC,      MO(_RAISE),        KC_DELETE,            KC_LEFT, KC_DOWN, KC_RGHT
    ),



    // +-----------------------------------------+      +-----------------------------------------+
    // | ESC  |      | date | date |      |      |      |  §   |  °   |  $   |  €   |  É   | BSPC |
    // |------------------------------------------      ------------------------------------------|
    // | TAB  |  @   |      |pastry|  ^Z  |      |      |  ±   |  !   |  ?   |  #   |  \   | ENT  |
    // |------------------------------------------      ------------------------------------------|
    // | LSFT |  ¨   |      |  Ç   |  ^Y  |      |      |  µ   |  ~   |  &   |  |   |  UP  | GRV  |
    // |------------------------------------------      ------------------------------------------|
    // |      | LCTL | LALT | LGUI | LOW  | SPC  |      | SPC  | RAIS | DEL  | LEFT | DOWN | RGHT |
    // +-----------------------------------------+      +-----------------------------------------+

    [_LOWER] = LAYOUT(
        KC_ESC,  KC_NO,   ST_MACRO_100, ST_MACRO_101,   KC_NO,      KC_NO,  FR_SECT,        FR_DEG,     FR_DLR,     FR_EURO,    ST_MACRO_102,   KC_BSPC,
        KC_TAB,  FR_AT,   KC_NO,        ST_MACRO_103,   LCTL(FR_Z), KC_NO,  ST_MACRO_104,   FR_EXLM,    FR_QUES,    FR_HASH,    FR_BSLS,        KC_ENT,
        KC_LSFT, FR_DIAE, KC_NO,        ST_MACRO_105,   LCTL(KC_Y), KC_NO,  FR_MICR,        FR_TILD,    FR_AMPR,    FR_PIPE,    KC_UP,          FR_GRV,
        KC_NO,   KC_LCTL, KC_LALT,      KC_LGUI,        MO(_LOWER), KC_SPC, KC_SPC,         MO(_RAISE), KC_DELETE,  KC_LEFT,    KC_DOWN,        KC_RGHT
    ),



    // +-----------------------------------------+      +-----------------------------------------+
    // | ESC  |  :   |  '   |  "   |  +   |      |      |      |  7  [E] 8  [F] 9   |  è   | BSPC |
    // |------------------------------------------      ------------------------------------------|
    // | TAB  |  à   |  -   |  *   |  .   |  =   |      |  _   |  4  [C] 5  [D] 6   |  0   | ENT  |
    // |------------------------------------------      ------------------------------------------|
    // | CAP  |  ^   |  ù   |  ç   |  /   | <{[( |      | )]}> |  1  [A] 2  [B] 3   |  .   |  %   |
    // |------------------------------------------      ------------------------------------------|
    // |      | LCTL | LALT | LGUI | LOW  | SPC  |      | SPC  | RAIS | DEL  |      |      |      |
    // +-----------------------------------------+      +-----------------------------------------+

    [_RAISE] = LAYOUT(
        KC_ESC,      FR_COLN, FR_QUOT,     FR_DQUO,        KC_KP_PLUS,  KC_NO,          KC_NO,          KC_KP_7,      KC_KP_8,    KC_KP_9,  FR_EGRV,   KC_BSPC,
        KC_TAB,      FR_AGRV, KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_DOT,   KC_EQUAL,       FR_UNDS,        KC_KP_4,      KC_KP_5,    KC_KP_6,  KC_KP_0,   KC_ENT,
        KC_CAPSLOCK, FR_CIRC, FR_UGRV,     FR_CCED,        KC_KP_SLASH, TD(DANCE_200),  TD(DANCE_201),  KC_KP_1,      KC_KP_2,    KC_KP_3,  KC_KP_DOT, FR_PERC,
        KC_NO,       KC_LCTL, KC_LALT,     KC_LGUI,        MO(_LOWER),  KC_SPC,         KC_SPC,         MO(_RAISE),   KC_DELETE,  KC_NO,    KC_NO,     KC_NO
    ),



    // +-----------------------------------------+      +-----------------------------------------+
    // | RST  |      |      |      | SCLK | NMLK |      |      |      |      |      |      |      |
    // |------------------------------------------      ------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |      |
    // |------------------------------------------      ------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |      |
    // |------------------------------------------      ------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------+      +-----------------------------------------+

    [_ADJUST] = LAYOUT(
          RESET, KC_NO, KC_NO, KC_NO, KC_NUMLOCK,  KC_SCROLLLOCK, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),



    // +-----------------------------------------+      +-----------------------------------------+
    // |      |  F7  |  F8  |  F9  | F12  |      |      |      |      |      |      |      | PSCR |
    // |------------------------------------------      ------------------------------------------|
    // |      |  F4  |  F5  |  F6  | F11  |      |      |      |      |      |      |      |      |
    // |------------------------------------------      ------------------------------------------|
    // | LSFT |  F1  |  F2  |  F3  | F10  |      |      |      |      |      | PLAY | VOL+ | MUTE |
    // |------------------------------------------      ------------------------------------------|
    // |      | LCTL | LALT | LGUI |      |      |      |      |      |      |  <<  | VOL- |  >>  |
    // +-----------------------------------------+      +-----------------------------------------+

    [_FUNCTION] = LAYOUT(
        KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,             KC_PSCREEN,
        KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,             KC_NO,
        KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_VOL_UP,   KC_AUDIO_MUTE,
        KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK
    ),



    // +-----------------------------------------+      +-----------------------------------------+
    // |      |      |      |      |      |      |      | PGUP | HOME |  UP  | END  | ^F10 | BSPC |
    // |------------------------------------------      ------------------------------------------|
    // |      |      |      |      | LSFT |      |      | PGDW | LEFT | DOWN | RGHT | !^T  | ENT  |
    // |------------------------------------------      ------------------------------------------|
    // |      |      |      |      | ALT  |      |      |  F2  |!PGUP |      |!PGDW | !^N  | !^W  |
    // |------------------------------------------      ------------------------------------------|
    // |      |      |      |      |      | SPC  |      | SPC  | LCTL | SUBL |      |      |      |
    // +-----------------------------------------+      +-----------------------------------------+

    [_ARROWS] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_PGUP,   KC_HOME,       KC_UP,            KC_END,             LSFT(KC_F10),       KC_BSPC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LSHIFT, KC_NO,   KC_PGDOWN, KC_LEFT,       KC_DOWN,          KC_RIGHT,           LCTL(LSFT(KC_T)),   KC_ENT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT,   KC_NO,   KC_F2,     LCTL(KC_PGUP), KC_NO,            LCTL(KC_PGDOWN),    LCTL(LSFT(KC_N)),   LCTL(LSFT(FR_W)),
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_SPC,  KC_SPC,    KC_LCTRL,      TD(DANCE_500),    KC_NO,              KC_NO,              KC_NO
    ),



    // +-----------------------------------------+      +-----------------------------------------+
    // |      |      |      |      |      |      |      |      | +!1  | +!2  | +!3  |      |      |
    // |------------------------------------------      ------------------------------------------|
    // |      |      |      |      |      |      |      |      |fold 1|fold 2|fold 3|fold 0|      |
    // |------------------------------------------      ------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |      |
    // |------------------------------------------      ------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------+      +-----------------------------------------+

    [_SUBLIME] = LAYOUT(
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(LALT(KC_KP_1)), LSFT(LALT(KC_KP_2)), LSFT(LALT(KC_KP_3)),   KC_NO,          KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, ST_MACRO_600,        ST_MACRO_601,        ST_MACRO_602,          ST_MACRO_603,   KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,               KC_NO,                 KC_NO,          KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,               KC_NO,                 KC_NO,          KC_NO
    ),

};



// /////////////////////////////////////////////////////////////////////////////
// MISC FUNCTION
// /////////////////////////////////////////////////////////////////////////////



layer_state_t layer_state_set_user(layer_state_t state)
{
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



// /////////////////////////////////////////////////////////////////////////////
// LEDS
// /////////////////////////////////////////////////////////////////////////////



bool led_update_user(led_t led_state)
{
    board_set_led_by_index(0, LED_YELLOW, led_state.caps_lock);
    board_set_led_by_index(1, LED_YELLOW, led_state.scroll_lock);

    return false;
}



// /////////////////////////////////////////////////////////////////////////////
// MACROS
// /////////////////////////////////////////////////////////////////////////////



bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {

        case ST_MACRO_100:
            // macro autohotkey insert date & time
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_SCOLON) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_H) SS_DELAY(100) SS_TAP(X_SCOLON));
            }
            break;


        case ST_MACRO_101:
            // macro autohotkey insert date
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_SCOLON) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_8) SS_DELAY(100) SS_TAP(X_8));
            }
            break;

        case ST_MACRO_102:
            // insert alt code for É
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_4) ));
            }
            break;


        case ST_MACRO_103:
            // macro sublime pastry
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_N))) SS_DELAY(100) SS_TAP(X_KP_0)  SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;


        case ST_MACRO_104:
            // insert alt code ±
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_1) ));
            }
            break;


        case ST_MACRO_105:
            // insert alt code Ç
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_8) ));
            }
            break;

        case ST_MACRO_600:
            // macro sublime fold level 1
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_KP_1)));
            }
            break;

        case ST_MACRO_601:
            // macro sublime fold level 2
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_KP_2)));
            }
            break;

        case ST_MACRO_602:
            // macro sublime fold level 3
            if (record->event.pressed) {
              SEND_STRING(SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_KP_3)));

            }
            break;

        case ST_MACRO_603:
            // macro sublime fold level 0
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_KP_0)));
            }
            break;

        default:
            break;
    }

    return true;

}




// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE : General Definitions
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



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 200 : Opening Brackets
// /////////////////////////////////////////////////////////////////////////////



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

void on_dance_200(qk_tap_dance_state_t *state, void *user_data);
void dance_200_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_200_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_200(qk_tap_dance_state_t *state, void *user_data)
{
    if( state->count == 3 )
    {
        tap_code16(FR_LPRN);
        tap_code16(FR_LPRN);
        tap_code16(FR_LPRN);
    }

    if( state->count > 3 )
    {
        tap_code16(FR_LPRN);
    }
}

void dance_200_finished(qk_tap_dance_state_t *state, void *user_data)
{
    dance_state[2].step = dance_step(state);

    switch( dance_state[2].step )
    {
        case SINGLE_TAP:
            register_code16(FR_LPRN);
            break;

        case SINGLE_HOLD:
            register_code16(FR_LABK);
            break;

        case DOUBLE_TAP:
            register_code16(RALT(KC_5));
            break;

        case DOUBLE_HOLD:
            register_code16(RALT(KC_4));
            break;

        case DOUBLE_SINGLE_TAP:
            tap_code16(FR_LPRN);
            register_code16(FR_LPRN);
            break;

        default:
            break;
    }
}

void dance_200_reset(qk_tap_dance_state_t *state, void *user_data)
{
    wait_ms(10);

    switch( dance_state[2].step )
    {
        case SINGLE_TAP:
            unregister_code16(FR_LPRN);
            break;

        case SINGLE_HOLD:
            unregister_code16(FR_LABK);
            break;

        case DOUBLE_TAP:
            unregister_code16(RALT(KC_5));
            break;

        case DOUBLE_HOLD:
            unregister_code16(RALT(KC_4));
            break;

        case DOUBLE_SINGLE_TAP:
            unregister_code16(FR_LPRN);
            break;

        default:
            break;
    }

    dance_state[2].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 201 : Closing Brackets
// /////////////////////////////////////////////////////////////////////////////



void on_dance_201(qk_tap_dance_state_t *state, void *user_data);
void dance_201_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_201_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_201(qk_tap_dance_state_t *state, void *user_data)
{
    if( state->count == 3 )
    {
        tap_code16(FR_RPRN);
        tap_code16(FR_RPRN);
        tap_code16(FR_RPRN);
    }

    if( state->count > 3 )
    {
        tap_code16(FR_RPRN);
    }
}

void dance_201_finished(qk_tap_dance_state_t *state, void *user_data)
{
    dance_state[3].step = dance_step(state);

    switch( dance_state[3].step )
    {
        case SINGLE_TAP:
            register_code16(FR_RPRN);
            break;

        case SINGLE_HOLD:
            register_code16(RSFT(FR_RABK));
            break;

        case DOUBLE_TAP:
            register_code16(RALT(KC_MINUS));
            break;

        case DOUBLE_HOLD:
            register_code16(RALT(KC_EQUAL));
            break;

        case DOUBLE_SINGLE_TAP:
            tap_code16(FR_RPRN);
            register_code16(FR_RPRN);
            break;

        default:
            break;
    }
}

void dance_201_reset(qk_tap_dance_state_t *state, void *user_data)
{
    wait_ms(10);

    switch( dance_state[3].step )
    {
        case SINGLE_TAP:
            unregister_code16(FR_RPRN);
            break;

        case SINGLE_HOLD:
            unregister_code16(RSFT(FR_RABK));
            break;

        case DOUBLE_TAP:
            unregister_code16(RALT(KC_MINUS));
            break;

        case DOUBLE_HOLD:
            unregister_code16(RALT(KC_EQUAL));
            break;

        case DOUBLE_SINGLE_TAP:
            unregister_code16(FR_RPRN);
            break;

        default:
            break;
    }

    dance_state[3].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE 500 : sublime chahge case
// /////////////////////////////////////////////////////////////////////////////



void on_dance_500(qk_tap_dance_state_t *state, void *user_data);
void dance_500_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_500_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_500(qk_tap_dance_state_t *state, void *user_data)
{
    if( state->count == 3 )
    {
        tap_code16(LCTL(KC_U));
        tap_code16(LCTL(KC_U));
        tap_code16(LCTL(KC_U));
    }

    if( state->count > 3 )
    {
        tap_code16(LCTL(KC_U));
    }
}

void dance_500_finished(qk_tap_dance_state_t *state, void *user_data)
{
    dance_state[1].step = dance_step(state);

    switch (dance_state[1].step)
    {
        case SINGLE_TAP:
            register_code16(LCTL(KC_U));
            break;

        case SINGLE_HOLD:
            register_code16(KC_ENTER);
            break;

        case DOUBLE_TAP:
            register_code16(LCTL(LSFT(KC_U)));
            break;

        case DOUBLE_HOLD:
            register_code16(LALT(LCTL(LSFT(KC_U))));
            break;

        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(KC_U));
            register_code16(LCTL(KC_U));
            break;

        default:
            break;
    }
}

void dance_500_reset(qk_tap_dance_state_t *state, void *user_data)
{
    wait_ms(10);

    switch( dance_state[1].step )
    {
        case SINGLE_TAP:
            unregister_code16(LCTL(KC_U));
            break;

        case SINGLE_HOLD:
            unregister_code16(KC_ENTER);
            break;

        case DOUBLE_TAP:
            unregister_code16(LCTL(LSFT(KC_U)));
            break;

        case DOUBLE_HOLD:
            unregister_code16(LALT(LCTL(LSFT(KC_U))));
            break;

        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(KC_U));
            break;

        default:
            break;
    }

    dance_state[1].step = 0;
}



// /////////////////////////////////////////////////////////////////////////////
// TAP DANSE : DO STUFF
// /////////////////////////////////////////////////////////////////////////////



qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_200] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_200, dance_200_finished, dance_200_reset),
    [DANCE_201] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_201, dance_201_finished, dance_201_reset),
    [DANCE_500] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_500, dance_500_finished, dance_500_reset),
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


