#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _VIM
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

// Layers
#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define ADJUST   MO(_ADJUST)
#define VIM      MO(_VIM)
// remapping CTRL
#define CTL_ESC  CTL_T(KC_ESC)
#define CTL_QUT  CTL_T(KC_QUOT)
// remapping SHIFT
#define SFT_ENT  RSFT_T(KC_ENT)
#define CD_LEFT  GUI_T(KC_LEFT)
// remapping the arrow keys
#define AL_DOWN  ALT_T(KC_DOWN)
#define CTL_UP   CTL_T(KC_UP)
#define ADJ_RGHT LT(_ADJUST, KC_RGHT)
#define VI_SCLN  LT(_VIM, KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_all(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   _______, KC_H,    KC_J,    KC_K,    KC_L,    VI_SCLN, CTL_QUT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_ENT, KC_SPC,  RAISE,   CD_LEFT, AL_DOWN, CTL_UP,  ADJ_RGHT
),

[_COLEMAK] = LAYOUT_all(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   _______,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   _______,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, _______,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_DVORAK] = LAYOUT_all(
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,             KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   _______,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   _______,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, _______,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_all(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_all(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_DEL,  _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, _______, _______, _______, _______, _______, _______, KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ADJUST] =  LAYOUT_all(
  _______, RESET,   _______, _______, _______, _______,          _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, KC_SLCK, AU_ON,   AU_OFF,  AG_NORM, _______, AG_SWAP,  QWERTY, COLEMAK,  DVORAK, _______, _______,
  _______, _______, _______, KC_CAPS, _______, _______, _______, KC_NLCK, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_VIM] =  LAYOUT_all(
  _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
             }
             break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code16(S(KC_VOLD));
    } else {
      tap_code16(KC_VOLU);
    }
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("COLEMAK\n"), false);
            break;
        case _DVORAK:
            oled_write_P(PSTR("DVORAK\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST\n"), false);
            break;
        case _VIM:
            oled_write_P(PSTR("VIM\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    oled_write_ln_P(PSTR(""), false);
    
    // Host Keyboard LED output character
}
#endif
