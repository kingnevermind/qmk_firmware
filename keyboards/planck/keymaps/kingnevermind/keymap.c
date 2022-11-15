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
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTION,
    _ARROWS,
    _SUBLIME,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
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
        KC_ESC,        FR_Q,    FR_W,    LT(5,KC_F),        KC_P,              KC_B,   KC_J,        KC_L,              KC_U,                 KC_Y,    FR_EACU, KC_BSPC,
        KC_TAB,        FR_A,    KC_R,    KC_S,              KC_T,              KC_G,   KC_H,        KC_N,              KC_E,                 KC_I,    KC_O,    KC_ENT,
        OSM(MOD_LSFT), FR_Z,    KC_X,    MT(MOD_LCTL,KC_C), MT(MOD_LSFT,KC_D), KC_V,   TD(DANCE_0), MT(MOD_RSFT,FR_M), MT(MOD_LCTL,FR_COMM), FR_DOT,  KC_UP,   FR_SCLN,
        MO(4),         KC_LCTL, KC_LALT, KC_LGUI,           LOWER,             KC_SPC, KC_SPC,      RAISE,             KC_DELETE,            KC_LEFT, KC_DOWN, KC_RGHT),



    // +-----------------------------------------------------------------------------------+
    // | ESC  |      |      |      |      |      |  §   |  °   |  $   |  €   |      | BSPC |
    // |-----------------------------------------------------------------------------------|
    // | TAB  |  @   |      |      |      |      |      |  !   |  ?   |  #   |  \   | ENT  |
    // |-----------------------------------------------------------------------------------|
    // | LSFT |  ¨   |      |      |      |      |  µ   |  ~   |  &   |  |   |  UP  | GRV  |
    // |-----------------------------------------------------------------------------------|
    // |      | LCTL | LALT | LGUI | LOW  | SPC  | SPC  | RAIS | DEL  | LEFT | DOWN | RGHT |
    // +-----------------------------------------------------------------------------------+

    [_LOWER] = LAYOUT_planck_grid(
        KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,  FR_SECT, FR_DEG,  FR_DLR,    FR_EURO, KC_NO,   KC_BSPC,
        KC_TAB,  FR_AT,   KC_NO,   KC_NO,   KC_NO, KC_NO,  KC_NO,   FR_EXLM, FR_QUES,   FR_HASH, FR_BSLS, KC_ENT,
        KC_LSFT, FR_DIAE, KC_NO,   KC_NO,   KC_NO, KC_NO,  FR_MICR, FR_TILD, FR_AMPR,   FR_PIPE, KC_UP,   FR_GRV,
        KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC,  RAISE,   KC_DELETE, KC_LEFT, KC_DOWN, KC_RGHT),



    // +-----------------------------------------------------------------------------------+
    // | ESC  |  :   |  '   |  "   |  +   |      |      |  7   |  8   |  9   |  è   | BSPC |
    // |-----------------------------------------------------------------------------------|
    // | TAB  |  à   |  -   |  *   |  .   |  =   |  _   |  4   |  5   |  6   |  0   | ENT  |
    // |-----------------------------------------------------------------------------------|
    // | CAP  |  ^   |  ù   |  ç   |  /   | <{[( | )]}> |  1   |  2   |  3   |  .   |  %   |
    // |-----------------------------------------------------------------------------------|
    // |      | LCTL | LALT | LGUI | LOW  | SPC  | SPC  | RAIS | DEL  |      |      |      |
    // +-----------------------------------------------------------------------------------+

    [_RAISE] = LAYOUT_planck_grid(
        KC_ESC,      FR_COLN, FR_QUOT,     FR_DQUO,        KC_KP_PLUS,  KC_NO,          KC_NO,          KC_KP_7,  KC_KP_8,   KC_KP_9, FR_EGRV,   KC_BSPC,
        KC_TAB,      FR_AGRV, KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_DOT,   KC_EQUAL,       FR_UNDS,        KC_KP_4,  KC_KP_5,   KC_KP_6, KC_KP_0,   KC_ENT,
        KC_CAPSLOCK, FR_CIRC, FR_UGRV,     FR_CCED,        KC_KP_SLASH, TD(DANCE_2),    TD(DANCE_3),    KC_KP_1,  KC_KP_2,   KC_KP_3, KC_KP_DOT, FR_PERC,
        KC_NO,       KC_LCTL, KC_LALT,     KC_LGUI,        LOWER,       KC_SPC,         KC_SPC,         RAISE,    KC_DELETE, KC_NO,   KC_NO,     KC_NO),



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
    // |      |      |      |      |      | SPC  | SPC  | LCTL |      |      |      |      |
    // +-----------------------------------------------------------------------------------+

    [_ARROWS] = LAYOUT_planck_grid(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_PGUP,   KC_HOME,       KC_UP,        KC_END,          LSFT(KC_F10),     KC_BSPC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LSHIFT, KC_NO,   KC_PGDOWN, KC_LEFT,       KC_DOWN,      KC_RIGHT,        LCTL(LSFT(KC_T)), KC_ENT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT,   KC_NO,   KC_F2,     LCTL(KC_PGUP), KC_NO,        LCTL(KC_PGDOWN), LCTL(LSFT(KC_N)), LCTL(LSFT(FR_W)),
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_SPC,  KC_SPC,    KC_LCTRL,      KC_NO,        KC_NO,           KC_NO,            KC_NO),



    // +-----------------------------------------------------------------------------------+
    // |      |      |      |      |      |      |      | +!1  | +!2  | +!3  |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // |-----------------------------------------------------------------------------------|
    // |      |      |      |      |      |      |      |      |      |      |      |      |
    // +-----------------------------------------------------------------------------------+

    [_SUBLIME] = LAYOUT_planck_grid(
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(LSFT(KC_KP_1)), LALT(LSFT(KC_KP_2)), LALT(LSFT(KC_KP_3)), KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,               KC_NO,               KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,               KC_NO,               KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO,               KC_NO,               KC_NO, KC_NO),
};







// #ifdef AUDIO_ENABLE
//   float plover_song[][2]     = SONG(PLOVER_SOUND);
//   float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
// #endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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


static tap dance_state[4];
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


// // /////////////////////////////////////////////////////////////////////////////
// //
// // /////////////////////////////////////////////////////////////////////////////


// void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
// void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);
//
// void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
//     if(state->count == 3) {
//         tap_code16(KC_KP_SLASH);
//         tap_code16(KC_KP_SLASH);
//         tap_code16(KC_KP_SLASH);
//     }
//     if(state->count > 3) {
//         tap_code16(KC_KP_SLASH);
//     }
// }
//
// void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
//     dance_state[1].step = dance_step(state);
//     switch (dance_state[1].step) {
//         case SINGLE_TAP: register_code16(KC_KP_SLASH); break;
//         case DOUBLE_TAP: register_code16(KC_KP_SLASH); register_code16(KC_KP_SLASH); break;
//         case DOUBLE_HOLD: register_code16(RALT(KC_8)); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_SLASH); register_code16(KC_KP_SLASH);
//     }
// }
//
// void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (dance_state[1].step) {
//         case SINGLE_TAP: unregister_code16(KC_KP_SLASH); break;
//         case DOUBLE_TAP: unregister_code16(KC_KP_SLASH); break;
//         case DOUBLE_HOLD: unregister_code16(RALT(KC_8)); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_SLASH); break;
//     }
//     dance_state[1].step = 0;
// }



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











qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        // [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        // [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        // [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        // [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        // [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        // [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        // [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        // [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        // [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        // [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        // [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        // [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        // [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        // [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
};



















// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         print("mode just switched to qwerty and this is a huge string\n");
//         set_single_persistent_default_layer(_QWERTY);
//       }
//       return false;
//       break;
//     case COLEMAK:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_COLEMAK);
//       }
//       return false;
//       break;
//     case DVORAK:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_DVORAK);
//       }
//       return false;
//       break;
//     case BACKLIT:
//       if (record->event.pressed) {
//         register_code(KC_RSFT);
//         #ifdef BACKLIGHT_ENABLE
//           backlight_step();
//         #endif
//         #ifdef KEYBOARD_planck_rev5
//           writePinLow(E6);
//         #endif
//       } else {
//         unregister_code(KC_RSFT);
//         #ifdef KEYBOARD_planck_rev5
//           writePinHigh(E6);
//         #endif
//       }
//       return false;
//       break;
//     case PLOVER:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           stop_all_notes();
//           PLAY_SONG(plover_song);
//         #endif
//         layer_off(_RAISE);
//         layer_off(_LOWER);
//         layer_off(_ADJUST);
//         layer_on(_PLOVER);
//         if (!eeconfig_is_enabled()) {
//             eeconfig_init();
//         }
//         keymap_config.raw = eeconfig_read_keymap();
//         keymap_config.nkro = 1;
//         eeconfig_update_keymap(keymap_config.raw);
//       }
//       return false;
//       break;
//     case EXT_PLV:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_gb_song);
//         #endif
//         layer_off(_PLOVER);
//       }
//       return false;
//       break;
//   }
//   return true;
// }

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// bool encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       #ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_DOWN);
//       #else
//         tap_code(KC_PGDN);
//       #endif
//     } else {
//       #ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_UP);
//       #else
//         tap_code(KC_PGUP);
//       #endif
//     }
//   }
//     return true;
// }

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0: {
// #ifdef AUDIO_ENABLE
//             static bool play_sound = false;
// #endif
//             if (active) {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) { PLAY_SONG(plover_song); }
// #endif
//                 layer_on(_ADJUST);
//             } else {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) { PLAY_SONG(plover_gb_song); }
// #endif
//                 layer_off(_ADJUST);
//             }
// #ifdef AUDIO_ENABLE
//             play_sound = true;
// #endif
//             break;
//         }
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
//     return true;
// }

// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }

// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case RAISE:
//     case LOWER:
//       return false;
//     default:
//       return true;
//   }
// }
