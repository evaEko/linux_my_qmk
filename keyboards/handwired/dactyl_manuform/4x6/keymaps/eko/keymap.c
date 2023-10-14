#include QMK_KEYBOARD_H
enum layers {
    _QWERTY = 0,
    _SPECIAL_CHARS,
    _NUMBERS
};

#define QWERTY   DF(_QWERTY)
#define NUMS  DF(_NUMBERS)
#define SPC   DF(_SPECIAL_CHARS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_SLSH,  KC_Q,              KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LSFT,  KC_A,              KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
        KC_LCTL,  LT(SPC,KC_Z),LT(NUMS,KC_X),    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM,LT(NUMS,KC_DOT),LT(SPC,KC_QUOT), KC_LCTL,
                          KC_ESC, KC_LALT,                                                KC_GRV, KC_BSLS,
                                            KC_DEL,   KC_SPC,             KC_ENT,  KC_ENT,
                                            KC_TAB,  KC_HOME,            KC_END,  KC_SPC,
                                            KC_BSPC, KC_GRV,             KC_LGUI, KC_EQL
    ),

    [_SPECIAL_CHARS] = LAYOUT(
     KC_TRNS ,KC_EXLM, KC_AT  ,  KC_HASH,  KC_DLR,  KC_PERC,                                    KC_CIRC,KC_AMPR,  KC_ASTR, KC_LPRN,KC_RPRN, KC_TRNS,
     KC_TRNS ,KC_LBRC, KC_RBRC,  KC_LCBR, KC_RCBR,  KC_TRNS,                                    KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT,KC_TRNS, KC_TRNS,
     KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_HOME,KC_END,  KC_TRNS, KC_QUOT,KC_TRNS , KC_TRNS,
                          KC_ESC, KC_LALT,                                                KC_GRV, KC_BSLS,
                                            KC_DEL,   KC_SPC,             KC_ENT,  KC_ENT,
                                            KC_TAB,  KC_HOME,            KC_END,  KC_SPC,
                                            KC_BSPC, KC_GRV,             KC_LGUI, KC_EQL

    ),

    [_NUMBERS] = LAYOUT(
     KC_TRNS, KC_1,  KC_2 ,  KC_3 ,   KC_4 ,   KC_5,                                        KC_6,   KC_7,  KC_8, KC_9 ,KC_0 , KC_TRNS,
     KC_TRNS ,KC_LBRC, KC_RBRC,  KC_LCBR, KC_RCBR,  KC_TRNS,                                    KC_MS_LEFT, KC_MS_DOWN,  KC_MS_UP , KC_MS_RIGHT,KC_TRNS, KC_TRNS,
     KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_HOME,KC_END,  KC_TRNS, KC_QUOT,KC_TRNS , KC_TRNS,
                          KC_ESC, KC_LALT,                                                               KC_GRV, KC_BSLS,
                                            KC_DEL,   KC_SPC,             KC_BTN3,  KC_BTN3,
                                            KC_TAB,  KC_HOME,            KC_END,  KC_BTN2,
                                            KC_BSPC, KC_GRV,             KC_LGUI, KC_BTN4
    )


};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
