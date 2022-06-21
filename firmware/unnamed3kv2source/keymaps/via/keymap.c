#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        KC_Z,    KC_X,    KC_C ),

    [1] = LAYOUT(
        RGB_MOD,    RGB_TOG,    TO(2)),
    
    [2] = LAYOUT(
        RGB_HUI, RGB_HUD, TO(3)),

    [3] = LAYOUT(
        RGB_SAI, RGB_SAD, TO(4)),

    [4] = LAYOUT(
        RGB_VAI, RGB_VAD, TO(0)),

};

void bootmagic_lite(void) {
    matrix_scan();
    wait_ms(DEBOUNCE * 2);
    matrix_scan();

    if (matrix_get_row(BOOTMAGIC_LITE_ROW) & (1 << BOOTMAGIC_LITE_COLUMN)) {
      // Go to FN layer when bootmagic key is held
      //bootloader_jump();
      layer_on(1);
    }
}

