#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _EXT 1
#define _LYR2 2
#define _LYR3 3

enum custom_keycodes {
  QWERTY = 0,
  EXT,
  LYR2,
  LYR3,
};

//static uint16_t default_animation = RGB_MATRIX_CYCLE_SPIRAL;
static int default_speed = 50;
//static uint16_t secondary_animation = RGB_MATRIX_HUE_WAVE;
static int secondary_speed = 150;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     EXT,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LYR2,              LYR3,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_LALT, KC_SPC,                    KC_SPC,  KC_LBRC, KC_RBRC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_EXT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  _______, _______, _______, KC_VOLU, KC_VOLU,                            KC_PGUP, _______, _______, _______, KC_MINS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_UP,   _______, _______, _______,                            KC_PGDN, _______, _______, _______, _______, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                            KC_HOME, _______, _______, _______, _______, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_END,  _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_CAPS,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LYR2] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                             _______, KC_NLCK, KC_PSLS, KC_PAST, _______, KC_PMNS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       RGB_TOG, RGB_RMOD, RGB_HUI,RGB_SAI, RGB_VAI, RGB_SPI,                            _______, KC_P7,   KC_P8,    KC_P9,  _______, KC_PPLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       BL_TOGG, BL_INC,  BL_DEC,  BL_BRTG,  _______, _______,                           _______, KC_P4,   KC_P5,    KC_P6,  _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_P1,   KC_P2,    KC_P3,  _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, _______,                   _______, KC_P0,    KC_PDOT
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LYR3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }

      return false;
    case EXT:
      if (record->event.pressed) {
        layer_on(_EXT);
      } else {
        layer_off(_EXT);
      }

      return false;
   case LYR2:
      if (record->event.pressed) {
        layer_on(_LYR2);
      } else {
        layer_off(_LYR2);
      }

      return false;

  case LYR3:
      if (record->event.pressed) {
       layer_on(_LYR3);
      } else {
       layer_off(_LYR3);
      }

         return false;
  }
  return true;
}


// RGB Layers (Enable animations in config.h)
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
            rgb_matrix_sethsv_noeeprom(HSV_AZURE);
            rgb_matrix_set_speed_noeeprom(secondary_speed);
            //rgb_matrix_mode_noeeprom(secondary_animation);
            break;
        case _EXT:
            rgb_matrix_sethsv_noeeprom(HSV_WHITE);
            rgb_matrix_set_speed_noeeprom(secondary_speed);
          //  rgb_matrix_mode_noeeprom(secondary_animation);
            break;
        case _LYR2:
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            rgb_matrix_set_speed_noeeprom(secondary_speed);
            //rgb_matrix_mode_noeeprom(secondary_animation);
            break;
        case _LYR3:
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            rgb_matrix_set_speed_noeeprom(secondary_speed);
          //  rgb_matrix_mode_noeeprom(secondary_animation);
            break;
        default:
            rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
            rgb_matrix_set_speed_noeeprom(default_speed);
            //rgb_matrix_mode_noeeprom(default_animation);
            break;
    }
    return state;
}
