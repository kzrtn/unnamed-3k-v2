#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x4B55
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER kzrtn
#define PRODUCT      kzrtn unnamed3kv2

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 3

#ifndef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#endif

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* direct pins */
#define DIRECT_PINS { \
    { B7, C7, C6} \
}

#define RGB_DI_PIN B3

#ifdef RGB_DI_PIN
  #define RGBLED_NUM 2
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 255
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_MOOD
#endif

#define DEBOUNCE 3

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12
#define FORCE_NKRO