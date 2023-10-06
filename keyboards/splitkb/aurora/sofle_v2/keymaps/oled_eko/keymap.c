#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include <action_layer.h>

enum layers {
    _QWERTY = 0,
    _SPECIAL_CHARS,
    _NUMBERS
};

enum {
  TD_CTRL_GUI = 0
};


#define QWERTY   DF(_QWERTY)
#define NUMS  DF(_NUMBERS)
#define SPC   DF(_SPECIAL_CHARS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_F1  ,  KC_F2,           KC_F3,   KC_F4,   KC_F5,   KC_F6,                           KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_F11,         KC_F12,
        KC_SLSH,  KC_Q,            KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,           KC_MINS,
        KC_LSFT,  KC_A,            KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,          KC_SCLN,        KC_RSFT,
 TD(TD_CTRL_GUI), LT(SPC,KC_Z),LT(NUMS,KC_X),KC_C,    KC_V,    KC_B,    KC_MUTE,     KC_TRNS,   KC_N,    KC_M,    KC_COMM,LT(NUMS,KC_DOT),LT(SPC,KC_QUOT),KC_RCTL,
                          KC_ESC, KC_LALT, KC_TAB,   KC_BSPC,  KC_DEL,                      KC_EQL, KC_SPC, KC_ENT, KC_GRV, KC_BSLS
    ),

    [_SPECIAL_CHARS] = LAYOUT(
     KC_F1   ,KC_F2,   KC_F3  ,  KC_F4,    KC_F5,   KC_F6,                                      KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
     KC_TRNS ,KC_EXLM, KC_AT  ,  KC_HASH,  KC_DLR,  KC_PERC,                                    KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN, KC_TRNS,
     KC_TRNS ,KC_LBRC, KC_RBRC,  KC_LCBR, KC_RCBR,  KC_TRNS,                                    KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT,  KC_TRNS, KC_TRNS,
     KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS,   KC_HOME, KC_END,  KC_TRNS, KC_QUOT,  KC_TRNS , KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

    ),

    [_NUMBERS] = LAYOUT(
     KC_F1   ,KC_F2,   KC_F3    ,  KC_F4,     KC_F5,    KC_F6,                                      KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
     KC_TRNS, KC_1,    KC_2     ,  KC_3 ,     KC_4 ,    KC_5,                                        KC_6,   KC_7,  KC_8, KC_9 ,KC_0 , KC_TRNS,
     KC_TRNS ,KC_LBRC, KC_RBRC  ,  KC_LCBR,   KC_RCBR,  KC_TRNS,                                    KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT,KC_TRNS, KC_TRNS,
     KC_TRNS ,KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_HOME,KC_END,  KC_TRNS, KC_QUOT,KC_TRNS , KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )


};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
};

void oled_write_fixed(const char *data) {
    char fixed_str[7];
    snprintf(fixed_str, sizeof(fixed_str), "%-6s", data); // Fill with spaces
    oled_write(fixed_str, false);
}


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

oled_rotation_t oled_init_user(oled_rotation_t rotation){
    return OLED_ROTATION_180;
}

char hex_to_ascii(uint8_t hex_value) {
    if (hex_value < 10) {
        return '0' + hex_value;
    } else if (hex_value < 16) {
        return 'A' + (hex_value - 10);
    } else {
        return '?'; // error value
    }
}

static char last_key[32] = "None";

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            //case KC_A: snprintf(last_key, sizeof(last_key), "A"); break;
            case KC_B: snprintf(last_key, sizeof(last_key), "B"); break;
            case KC_C: snprintf(last_key, sizeof(last_key), "C"); break;
            case KC_D: snprintf(last_key, sizeof(last_key), "D"); break;
            case KC_E: snprintf(last_key, sizeof(last_key), "E"); break;
            case KC_F: snprintf(last_key, sizeof(last_key), "F"); break;
            case KC_G: snprintf(last_key, sizeof(last_key), "G"); break;
            case KC_H: snprintf(last_key, sizeof(last_key), "H"); break;
            case KC_I: snprintf(last_key, sizeof(last_key), "I"); break;
            case KC_J: snprintf(last_key, sizeof(last_key), "J"); break;
            case KC_K: snprintf(last_key, sizeof(last_key), "K"); break;
            case KC_L: snprintf(last_key, sizeof(last_key), "L"); break;
            case KC_M:
                snprintf(last_key, sizeof(last_key), "M"); break;
            case KC_N: snprintf(last_key, sizeof(last_key), "N"); break;
            case KC_O: snprintf(last_key, sizeof(last_key), "O"); break;
            case KC_P: snprintf(last_key, sizeof(last_key), "P"); break;
            case KC_Q: snprintf(last_key, sizeof(last_key), "Q"); break;
            case KC_R: snprintf(last_key, sizeof(last_key), "R"); break;
            case KC_S: snprintf(last_key, sizeof(last_key), "S"); break;
            case KC_T: snprintf(last_key, sizeof(last_key), "T"); break;
            case KC_U: snprintf(last_key, sizeof(last_key), "U"); break;
            case KC_V: snprintf(last_key, sizeof(last_key), "V"); break;
            case KC_W: snprintf(last_key, sizeof(last_key), "W"); break;
            case KC_X:
                    snprintf(last_key, sizeof(last_key), "X");
            break;
            case KC_Y: snprintf(last_key, sizeof(last_key), "Y"); break;
            case KC_Z:
                    snprintf(last_key, sizeof(last_key), "Z");
            break;
            case KC_1: snprintf(last_key, sizeof(last_key), "1"); break;
            case KC_2: snprintf(last_key, sizeof(last_key), "2"); break;
            case KC_3: snprintf(last_key, sizeof(last_key), "3"); break;
            case KC_4: snprintf(last_key, sizeof(last_key), "4"); break;
            case KC_5: snprintf(last_key, sizeof(last_key), "5"); break;
            case KC_6: snprintf(last_key, sizeof(last_key), "6"); break;
            case KC_7: snprintf(last_key, sizeof(last_key), "7"); break;
            case KC_8: snprintf(last_key, sizeof(last_key), "8"); break;
            case KC_9: snprintf(last_key, sizeof(last_key), "9"); break;
            case KC_0: snprintf(last_key, sizeof(last_key), "0"); break;

            case KC_SPACE: snprintf(last_key, sizeof(last_key), "Space"); break;
            case KC_ENT: snprintf(last_key, sizeof(last_key), "Enter"); break;
            case KC_SLSH: snprintf(last_key, sizeof(last_key), "/"); break;
            case KC_MINS: snprintf(last_key, sizeof(last_key), "-"); break;
            case KC_LSFT: snprintf(last_key, sizeof(last_key), "Left Shift"); break;
            case KC_RSFT: snprintf(last_key, sizeof(last_key), "Shift"); break;
            case KC_LCTL: snprintf(last_key, sizeof(last_key), "LCtrl"); break;
            case KC_RCTL: snprintf(last_key, sizeof(last_key), "RCtrl"); break;
            case KC_COMM: snprintf(last_key, sizeof(last_key), "Comma"); break;
            case KC_DOT:
                    snprintf(last_key, sizeof(last_key), "Dot");
            break;
            case KC_SCLN: snprintf(last_key, sizeof(last_key), ";"); break;
            case KC_QUOT: snprintf(last_key, sizeof(last_key), "Quote"); break;
            case KC_ESC: snprintf(last_key, sizeof(last_key), "Esc"); break;
            case KC_LALT: snprintf(last_key, sizeof(last_key), "LAlt"); break;
            case KC_RALT: snprintf(last_key, sizeof(last_key), "RAlt"); break;
            case KC_EXLM: snprintf(last_key, sizeof(last_key), "!"); break;
            case KC_AT: snprintf(last_key, sizeof(last_key), "@"); break;
            case KC_HASH: snprintf(last_key, sizeof(last_key), "#"); break;
            case KC_DLR: snprintf(last_key, sizeof(last_key), "$"); break;
            case KC_PERC: snprintf(last_key, sizeof(last_key), "Perc"); break;
            case KC_CIRC: snprintf(last_key, sizeof(last_key), "^"); break;
            case KC_AMPR: snprintf(last_key, sizeof(last_key), "&"); break;
            case KC_ASTR: snprintf(last_key, sizeof(last_key), "*"); break;
            case KC_LPRN: snprintf(last_key, sizeof(last_key), "("); break;
            case KC_RPRN: snprintf(last_key, sizeof(last_key), ")"); break;
            case KC_LBRC: snprintf(last_key, sizeof(last_key), "["); break;
            case KC_RBRC: snprintf(last_key, sizeof(last_key), "]"); break;
            case KC_LCBR: snprintf(last_key, sizeof(last_key), "{"); break;
            case KC_RCBR: snprintf(last_key, sizeof(last_key), "}"); break;
            case KC_GRV: snprintf(last_key, sizeof(last_key), "` / ~"); break;
            case KC_DEL: snprintf(last_key, sizeof(last_key), "Delete"); break;
            case KC_BSLS: snprintf(last_key, sizeof(last_key), "\\ / |"); break;
            case KC_LEFT: snprintf(last_key, sizeof(last_key), "Left"); break;
            case KC_DOWN: snprintf(last_key, sizeof(last_key), "Down"); break;
            case KC_UP: snprintf(last_key, sizeof(last_key), "Up"); break;
            case KC_RGHT: snprintf(last_key, sizeof(last_key), "Right"); break;
            case KC_HOME: snprintf(last_key, sizeof(last_key), "Home"); break;
            case KC_END: snprintf(last_key, sizeof(last_key), "End"); break;
            case KC_F1: snprintf(last_key, sizeof(last_key), "F1"); break;
            case KC_F2: snprintf(last_key, sizeof(last_key), "F2"); break;
            case KC_F3: snprintf(last_key, sizeof(last_key), "F3"); break;
            case KC_F4: snprintf(last_key, sizeof(last_key), "F4"); break;
            case KC_F5: snprintf(last_key, sizeof(last_key), "F5"); break;
            case KC_F6: snprintf(last_key, sizeof(last_key), "F6"); break;
            case KC_F7: snprintf(last_key, sizeof(last_key), "F7"); break;
            case KC_F8: snprintf(last_key, sizeof(last_key), "F8"); break;
            case KC_F9: snprintf(last_key, sizeof(last_key), "F9"); break;
            case KC_F10: snprintf(last_key, sizeof(last_key), "F10"); break;
            case KC_F11: snprintf(last_key, sizeof(last_key), "F11"); break;
            case KC_F12: snprintf(last_key, sizeof(last_key), "F12"); break;
            case KC_TAB: snprintf(last_key, sizeof(last_key), "Tab"); break;
            case KC_BSPC: snprintf(last_key, sizeof(last_key), "Backspace"); break;
            case KC_PLUS: snprintf(last_key, sizeof(last_key), "+"); break;
            case KC_EQL: snprintf(last_key, sizeof(last_key), "="); break;
            case 0x5700: snprintf(last_key, sizeof(last_key), "Ctrl/ Gui"); break;
            case 0x411D: snprintf(last_key, sizeof(last_key), "LT/ Z"); break;
            case 0x421B: snprintf(last_key, sizeof(last_key), "LT/ X"); break;
            case 0x00AB: snprintf(last_key, sizeof(last_key), "Mute"); break;
            case 0x4134: snprintf(last_key, sizeof(last_key), "LT/'"); break;
            case 0x4237: snprintf(last_key, sizeof(last_key), "LT/."); break;
            //case LT(SPC, KC_QUOT): snprintf(last_key, sizeof(last_key), "Spc, '"); break;
            //case LT(NUMS, KC_X): snprintf(last_key, sizeof(last_key), "Nums, x"); break;
            default: snprintf(last_key, sizeof(last_key), "K%04X", keycode); break;
        }
    }
    return true;
}

#ifdef OLED_ENABLE
bool oled_task_user(){

    //uint8_t char_width = 5;
    //uint8_t char_height = 10;
    //uint8_t screen_width = 128;
    //uint8_t screen_height = 64;

    uint8_t x = 3;
    uint8_t y = 2;
    // uint8_t x = (screen_width - char_width) / 2;
    // uint8_t y = (screen_height - char_height) / 2;

    oled_set_cursor(x, y);
    oled_write_fixed(last_key);
    //oled_write(last_key, false);
    return false;
}
#endif


#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif

tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL_GUI]  = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI)
};
