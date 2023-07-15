#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum ctrl_layers {
    BASE_LAYER,
    FN_LAYER
};

// enum ctrl_keycodes {
//     U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
//     U_T_AGCR,              //USB Toggle Automatic GCR control
//     DBG_TOG,               //DEBUG Toggle On / Off
//     DBG_MTRX,              //DEBUG Toggle Matrix Prints
//     DBG_KBD,               //DEBUG Toggle Keyboard Prints
//     DBG_MOU,               //DEBUG Toggle Mouse Prints
//     MD_BOOT,               //Restart into bootloader after hold timeout
// };

#define FN MO(FN_LAYER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_LAYER] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SCRL, KC_PAUS,
        SE_SECT, SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    SE_PLUS, SE_ACUT, KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    SE_ARNG, SE_DIAE, SE_QUOT,   KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, SE_ADIA, KC_ENT,
        KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS, KC_RSFT,                              KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, FN,      KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [FN_LAYER] = LAYOUT(
        XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, RGB_MOD, RGB_TOG, RGB_VAD, RGB_VAI,            KC_MUTE, XXXXXXX, KC_SLEP,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MPLY, KC_MSTP, KC_VOLU,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MPRV, KC_MNXT, KC_VOLD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                            _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,          _______, _______, _______
    ),
    [RGB] = LAYOUT(
        ESC: 0,   F1: 1,    F2: 2,    F3: 3,    F4: 4,    F5: 5,    F6: 6,    F7: 7,    F8: 8,    F9: 9,    F10: 10,  F11: 11,  F12: 12,            PSCR: 13, SLCK: 14, PAUS: 15,
        GRV: 16,  1: 17,    2: 18,    3: 19,    4: 20,    5: 21,    6: 22,    7: 23,    8: 24,    9: 25,    0: 26,    MINS: 27, EQL: 28,  BSPC: 29, INS: 30,  HOME: 31, PGUP: 32,
        TAB: 33,  Q: 34,    W: 35,    E: 36,    R: 37,    T: 38,    Y: 39,    U: 40,    I: 41,    O: 42,    P: 43,    LBRC: 44, RBRC: 45, BSLS: 46, DEL: 47,  END: 48,  PGDN: 49,
        CAPS: 50, A: 51,    S: 52,    D: 53,    F: 54,    G: 55,    H: 56,    J: 57,    K: 58,    L: 59,    SCLN: 60, QUOT: 61, ENT: 62,
        LSFT: 63, Z: 64,    X: 65,    C: 66,    V: 67,    B: 68,    N: 69,    M: 70,    COMM: 71, DOT: 72,  SLSH: 73, RSFT: 74,                               UP: 75,
        LCTL: 76, LGUI: 77, LALT: 78,                   SPC: 79,                                  RALT: 80, Fn: 81,   APP: 82,  RCTL: 83,           LEFT: 84, DOWN: 85, RGHT: 86
    ),
	[MATRIX] = LAYOUT(
	    0,       1,       2,       3,       4,       5,       6,       7,       8,       9,       10,      11,      12,                 13,      14,      15,
	    16,      17,      18,      19,      20,      21,      22,      23,      24,      25,      26,      27,      28,      29,        30,      31,      32,
	    33,      34,      35,      36,      37,      38,      39,      40,      41,      42,      43,      44,      45,      46,        47,      48,      49,
	    50,      51,      52,      53,      54,      55,      56,      57,      58,      59,      60,      61,      62,
	    63,      64,      65,      66,      67,      68,      69,      70,      71,      72,      73,      74,                                   75,
	    76,      77,      78,                        79,                                 80,      81,      82,      83,                 84,      85,      86
	),
    */
};

// #ifdef _______
#undef _______
#define _______ {0x00, 0x00, 0x00}
#define RED     {0xFF, 0x00, 0x00}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [FN_LAYER] = {
        _______, RED    , RED    , RED    , _______, RED    , RED    , RED    , _______, RED    , RED    , RED    , RED    ,            RED    , _______, RED,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   RED    , RED    , RED    ,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   RED    , RED    , RED    ,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, RED    , RED    , _______, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    },
};

#undef _______
#define _______ KC_TRNS
// #endif

void matrix_init_user(void) {
    // rgb_enabled_flag = true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

void set_layer_color(int layer) {
    if (layer == BASE_LAYER) {
        rgb_matrix_set_color_all(0x3f, 0xff, 0xef);
    } else {
        for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            RGB rgb = {
                .r = pgm_read_byte(&ledmap[layer][i][0]),
                .g = pgm_read_byte(&ledmap[layer][i][1]),
                .b = pgm_read_byte(&ledmap[layer][i][2]),
            };
            if (rgb.r || rgb.g || rgb.b) {
                // float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
                // rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            } else {
                rgb_matrix_set_color(i, 0, 0, 0);
            }
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    // if (disable_layer_color ||
    //     rgb_matrix_get_flags() == LED_FLAG_NONE ||
    //     rgb_matrix_get_flags() == LED_FLAG_UNDERGLOW) {
    //         return;
    //     }
    set_layer_color(get_highest_layer(layer_state));
    return false;
}
