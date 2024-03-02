#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN1,
    _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * └───┴───┴───┘
     */
    [_BASE] = LAYOUT_ortho_2x3(
        KC_VOLD, KC_MUTE, KC_VOLU,
        KC_A,    KC_B,    KC_C
    ),
    [_FN1] = LAYOUT_ortho_2x3(
        KC_VOLD, KC_MUTE, KC_VOLU,
        KC_A,    KC_B,    KC_C
    ),
    [_FN2] = LAYOUT_ortho_2x3(
        KC_VOLD, KC_MUTE, KC_VOLU,
        KC_A,    KC_B,    KC_C
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 2));
        } else {
            tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 0));
        }
    }
    return false;
}

bool uplayer = false;
bool downlayer = false;

void update_layers(void) {
    if (uplayer) {
        layer_move(0);
    } else if (downlayer) {
        layer_move(2);
    } else {
        layer_move(1);
    }
}

bool dip_switch_update_user(uint8_t index, bool active) { 
    switch (index) {
        case 0:
            uplayer = active;
            // downlayer = false;
            update_layers();
            // if(active) {
            //     layer_move(0);
            // } else {
            //     layer_move(1);
            // }
            break;
        case 1:
            downlayer = active;
            // uplayer = false;
            update_layers();
            // if(active) {
            //     layer_move(2);
            // } else {
            //     layer_move(1);
            // }
            break;
    }
    return true;
}

void keyboard_pre_init_kb (void) {
  setPinOutput(F6);
  setPinOutput(F7);
  setPinOutput(B1);

  update_layers();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            writePinHigh(B1);
            writePinLow(F6);
            writePinLow(F7);
            break;
        case 1:
            writePinLow(B1);
            writePinHigh(F6);
            writePinLow(F7);
            break;
        default:
            writePinLow(B1);
            writePinLow(F6);
            writePinHigh(F7);
            break;
    }
    return state;
}

bool isPressed = false;
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        isPressed = true;
    } else {
        isPressed = false;
    }
}
