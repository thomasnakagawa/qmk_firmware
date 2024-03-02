#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * ├───┼───┼───┤
     * │ G │ H │ I │
     * └───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_A,    KC_B,    KC_C,
        KC_D,    KC_E, KC_F,
        KC_G, KC_H, KC_I
    )
};

// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][1][2] = {
//     [0] =  { ENCODER_CCW_CW(KC_D, KC_E)  }
// };
// #endif

// void keyboard_pre_init_kb (void) {
//   setPinOutput(B4);
//   writePinHigh(B4);
// }

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) { /* First encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 0));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 2, 0));
//         }
//     } else if (index == 1) { /* Second encoder */
//         if (clockwise) {
//             tap_code(KC_VOLD);
//         } else {
//             tap_code(KC_VOLU);
//         }
//     } else if (index == 2) {
//         if (clockwise) {
//             tap_code(KC_J);
//         } else {
//             tap_code(KC_K);
//         }
//     }
//     return false;
// }