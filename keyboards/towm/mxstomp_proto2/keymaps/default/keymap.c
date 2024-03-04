#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3,
    _FN4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_3x3(
        KC_X,    KC_Y,  KC_Z,
        KC_MUTE, KC_NO, KC_NO,
        KC_A,    KC_B,  KC_NO
    ),
    [_FN1] = LAYOUT_ortho_3x3(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN2] = LAYOUT_ortho_3x3(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN3] = LAYOUT_ortho_3x3(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

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
            update_layers();
            break;
        case 1:
            downlayer = active;
            update_layers();
            break;
    }
    return true;
}

int currentState = 0;
bool isPressed = false;

#define LAYER_0_PIN B3
#define LAYER_1_PIN B2
#define LAYER_2_PIN B6
#define BUZZER_PIN E6

void keyboard_pre_init_kb (void) {
  setPinOutput(LAYER_0_PIN);
  setPinOutput(LAYER_1_PIN);
  setPinOutput(LAYER_2_PIN);
  setPinOutput(BUZZER_PIN);
}

void updateLeds(void) {
    if (isPressed) {
        writePinLow(LAYER_0_PIN);
        writePinLow(LAYER_1_PIN);
        writePinLow(LAYER_2_PIN); 
    } else {
        switch (currentState) {
            case 0:
                writePinHigh(LAYER_0_PIN);
                writePinLow(LAYER_1_PIN);
                writePinLow(LAYER_2_PIN);
                break;
            case 1:
                writePinLow(LAYER_0_PIN);
                writePinHigh(LAYER_1_PIN);
                writePinLow(LAYER_2_PIN);
                break;
            case 2:
                writePinLow(LAYER_0_PIN);
                writePinLow(LAYER_1_PIN);
                writePinHigh(LAYER_2_PIN);
                break;
            default:
                writePinHigh(LAYER_0_PIN);
                writePinHigh(LAYER_1_PIN);
                writePinHigh(LAYER_2_PIN);
                break;
        }  
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    currentState = get_highest_layer(state);
    updateLeds();
    return state;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    isPressed = record->event.pressed;
    updateLeds();

    if (isPressed) {
        writePinHigh(BUZZER_PIN);
    } else {
        writePinLow(BUZZER_PIN);
    }
}
