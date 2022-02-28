 /* Copyright 2020 RGBKB
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
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY,
    _VIM,
    _FN,
    _ADJ
};

#define FN_ESC   LT(_FN, KC_ESC)
#define FN_CAPS  LT(_FN, KC_CAPS)
#define CTL_ESC  LCTL_T(KC_ESC)
#define VIM_LYR  LT(_VIM, KC_SCLN)
#define SFT_ENT  LSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_all(
        KC_NO,                                                                                                    KC_NO,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_NO,   KC_BSPC, 
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS, 
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,     KC_K,    KC_L,    VIM_LYR, KC_QUOT,
        SFT_ENT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_NO,   KC_SFTENT, 
        KC_NO,   KC_LGUI, KC_LALT, RGB_TOG, MO(_FN), KC_SPC, KC_SPC, MO(_ADJ), RGB_MOD, KC_RALT, KC_LGUI, KC_NO
    ),
    
    [_VIM] = LAYOUT_all(
        KC_NO,                                                                                                       KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,    KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,    KC_NO,
        KC_LCTL, KC_LGUI, KC_LALT, RGB_TOG, MO(_FN), KC_SPC, KC_SPC,  MO(_ADJ),  KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT
    ),

    [_FN] = LAYOUT_all(
        KC_NO,                                                                                                      KC_NO,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 , KC_NO,   KC_DEL,
        _______, KC_PGDN, KC_UP,   KC_PGUP, _______, KC_MINS, KC_EQL , KC_PGUP, _______, _______, KC_PSCR, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC, KC_RBRC, KC_PGDN, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJ] = LAYOUT_all(
        KC_NO,                                                                                                      KC_NO,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_PSCR,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, _______, KC_UNDS, KC_PLUS, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, _______, KC_LCBR, KC_RCBR, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______,
        _______, _______, _______, RGB_MOD, _______, _______, _______, KC_P0,   KC_PDOT, KC_NLCK, _______, _______
    )
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("RGBKB Pan\n"), false);
    oled_write_P(PSTR("Layer: "), false);
    uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
    switch (layer) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _VIM:
            oled_write_P(PSTR("VIM\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            //oled_write_ln_P(PSTR("Undefined"), false);
    }
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("Numlock On\n") : PSTR("           \n"), false);
    oled_write_P(led_state.caps_lock ? PSTR("Capslock On \n") : PSTR("           \n"), false);
}
#endif

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {         // First encoder - right
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) {  // Second encoder - left
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
