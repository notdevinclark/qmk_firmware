#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _GM 1
#define _L1 2 // Symbols
#define _L2 3 // Numbers
#define _L3 4 // Power and Controls
#define _L4 5 // F Keys and Layer Swaps

// Macro name shortcuts
#define QWERTY M(_QW)
#define GAMING M(_GM)

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_TAB,         KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_L3, KC_QUOT),
    KC_LSFT,        KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS),
    MO(_L3),        MO(_L1), KC_LGUI,                KC_ENT, KC_SPC,           KC_RALT, MO(_L2),          MO(_L3)
  ),
  [_GM] = LAYOUT( /* Gaming */
    KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R, KC_T,   KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,  KC_F, KC_G,   KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, LT(_L3, KC_QUOT),
    KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V, KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS),
    KC_ESC,  MO(_L2), KC_LGUI,              KC_SPC, KC_ENT,       KC_RALT, MO(_L1),          MO(_L3)
  ),
  [_L1] = LAYOUT( /* LAYER 1 */
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_PPLS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_EQL
  ),
  [_L2] = LAYOUT( /* LAYER 2 */
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8, KC_9,    KC_0, KC_MINS,
    KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5, KC_6,    KC_ASTR, KC_PPLS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_1,    KC_2, KC_3,    KC_SLSH, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,        KC_EQL
  ),
  [_L3] = LAYOUT( /* LAYER 3 */
    KC_POWER,  KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,  KC_TRNS, TG(_L4),
    KC_TRNS,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_MUTE, KC_VOLD, KC_VOLU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,           KC_TRNS
  ),
  [_L4] = LAYOUT( /* LAYER 3 */
    TG(_L4),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    KC_TRNS,   KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_TRNS,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_TRNS, KC_TRNS,                   QWERTY,  GAMING,           KC_TRNS, KC_TRNS,          KC_TRNS
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _GM:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_GM);
          }
          break;
        case _QW:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QW);
          }
          break;
      }
    return MACRO_NONE;
};
