#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

/* ======== Layers ======== */
enum planck_layers {
  BASE_LAYER,
  COLEMAK_LAYER,
  SHIFT_LAYER,
  PSI_LAYER,
  QWERTY_LAYER,
  GAMMA_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  META_LAYER
};

/* ======== Custom Keycodes ======== */
#define COLEMAK DF(COLEMAK_LAYER)         // Switch default layer to COLEMAK_LAYER
#define QWERTY  DF(QWERTY_LAYER)          // Switch default layer to QWERTY_LAYER
#define PSI     MO(PSI_LAYER)             // Momentarily move to PSI_LAYER
#define GAMMA   MO(GAMMA_LAYER)           // Momentarily move to GAMMA_LAYER
#define LOWER   MO(LOWER_LAYER)           // Momentarily move to LOWER_LAYER
#define RAISE   MO(RAISE_LAYER)           // Momentarily move to RAISE_LAYRE
#define SHIFT   LM(SHIFT_LAYER, MOD_LSFT) // Momentarily move to SHIFT_LAYER and activate modifier MOD_LSFT
#define CTL_TAB MT(MOD_LCTL, KC_TAB)      // Left control when held, tab when tapped

/* ======== Laoyout ======== */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_planck_grid(
    KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    CTL_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT ,
    KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LALT, PSI    , LOWER  , SHIFT  , KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  ),

  [COLEMAK_LAYER] = LAYOUT_planck_grid(
    _______, SE_Q   , SE_W   , SE_F   , SE_P   , SE_G   , SE_J   , SE_L   , SE_U   , SE_Y   , SE_SCLN, _______,
    _______, SE_A   , SE_R   , SE_S   , SE_T   , SE_D   , SE_H   , SE_N   , SE_E   , SE_I   , SE_O   , _______,
    _______, SE_Z   , SE_X   , SE_C   , SE_V   , SE_B   , SE_K   , SE_M   , SE_COMM, SE_DOT , SE_QUOT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [SHIFT_LAYER] = LAYOUT_planck_grid(
    // Since LSFT is enabled on this layer, only shifted symbols can go here
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SE_COLN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, SE_QUES, SE_EXLM, SE_DQUO, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [PSI_LAYER] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL ,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS ,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_MICR, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
  ),

  [QWERTY_LAYER] = LAYOUT_planck_grid(
    _______, SE_Q   , SE_W   , SE_E   , SE_R   , SE_T   , SE_Y   , SE_U   , SE_I   , SE_O   , SE_P   , _______,
    KC_TAB , SE_A   , SE_S   , SE_D   , SE_F   , SE_G   , SE_H   , SE_J   , SE_K   , SE_L   , SE_SCLN, _______,
    KC_LSFT, SE_Z   , SE_X   , SE_C   , SE_V   , SE_B   , SE_N   , SE_M   , SE_COMM, SE_DOT , SE_QUOT, KC_RSFT,
    KC_LCTL, KC_LGUI, _______, GAMMA  , _______, KC_SPC , _______, _______, _______, _______, _______, _______
  ),

  [GAMMA_LAYER] = LAYOUT_planck_grid(
    XXXXXXX, SE_1   , SE_2   , SE_3   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, SE_4   , SE_5   , SE_6   , SE_0   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, SE_7   , SE_8   , SE_9   , SE_DOT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [LOWER_LAYER] = LAYOUT_planck_grid(
    XXXXXXX, SE_AMPR, SE_AT  , SE_HASH, SE_DLR , XXXXXXX, XXXXXXX, SE_LPRN, SE_RPRN, SE_LABK, SE_RABK, XXXXXXX,
    XXXXXXX, SE_PLUS, SE_MINS, SE_EQL , SE_PERC, XXXXXXX, XXXXXXX, SE_LBRC, SE_RBRC, SE_LCBR, SE_RCBR, XXXXXXX,
    _______, SE_ASTR, SE_SLSH, SE_PIPE, SE_BSLS, XXXXXXX, XXXXXXX, SE_UNDS, SE_CIRC, SE_TILD, SE_GRV , _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [RAISE_LAYER] = LAYOUT_planck_grid(
    XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX, XXXXXXX, SE_1   , SE_2   , SE_3   , SE_COLN, XXXXXXX,
    XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX, XXXXXXX, SE_4   , SE_5   , SE_6   , SE_0   , XXXXXXX,
    _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, SE_7   , SE_8   , SE_9   , SE_DOT , _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [META_LAYER] = LAYOUT_planck_grid(
    XXXXXXX, QWERTY , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

/* ======== Combos ======== */
const uint16_t PROGMEM ae_combo[] = { KC_A, KC_E, COMBO_END };
const uint16_t PROGMEM ao_combo[] = { KC_A, KC_O, COMBO_END };
const uint16_t PROGMEM oe_combo[] = { KC_O, KC_E, COMBO_END };
combo_t key_combos[COMBO_COUNT] = {
  COMBO(ae_combo, SE_ADIA),
  COMBO(ao_combo, SE_ARNG),
  COMBO(oe_combo, SE_ODIA)
};

/* ======== Logic ======== */
enum planck_colors {
  COLEMAK_COLOR,
  QWERTY_COLOR,
  META_COLOR,
  COLOR_COUNT
};

const rgblight_segment_t PROGMEM colemak_color[] = RGBLIGHT_LAYER_SEGMENTS({ 0, RGBLED_NUM, HSV_GOLD });
const rgblight_segment_t PROGMEM qwerty_color[] = RGBLIGHT_LAYER_SEGMENTS({ 0, RGBLED_NUM, HSV_RED });
const rgblight_segment_t PROGMEM meta_color[] = RGBLIGHT_LAYER_SEGMENTS({ 0, RGBLED_NUM, HSV_WHITE });

const rgblight_segment_t* const PROGMEM rgb_layers[] = {
  [COLEMAK_COLOR] = colemak_color,
  [QWERTY_COLOR] = qwerty_color,
  [META_COLOR] = meta_color,
  [COLOR_COUNT] = NULL
};

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(COLEMAK_COLOR, layer_state_cmp(state, COLEMAK_LAYER));
  rgblight_set_layer_state(QWERTY_COLOR, layer_state_cmp(state, QWERTY_LAYER));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, LOWER_LAYER, RAISE_LAYER, META_LAYER);
  rgblight_set_layer_state(META_COLOR, layer_state_cmp(state, META_LAYER));
  return state;
}

void keyboard_post_init_user(void) {
  rgblight_layers = rgb_layers;

  set_single_persistent_default_layer(COLEMAK_LAYER); // Always default to colemak
  rgblight_set_layer_state(COLEMAK_COLOR, true); // True, because we are certain that Colemak is activated
}
