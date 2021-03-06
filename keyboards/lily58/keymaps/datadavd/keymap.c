/* Copyright 2021 David Dansby
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _SUPER,
  _RAISE,
  _MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+----- |
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | \|   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+----- |
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ;:  |  '"  |
 * |------+------+------+------+------+------|   `~  |    | Enter |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,<  |  .>  |  ?/  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  [   | LAlt | LGUI | /SUPER  /       \Space \  |RAISE | RGUI |   ]  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_GRV, KC_ENT,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LBRC, KC_LALT, KC_LGUI, MO(_SUPER), KC_SPC, MO(_RAISE), KC_RGUI, KC_RBRC
),
/* SUPER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Pwr  |Pwr Dn| Sleep| Wake | XXXX | XXXX |                    |  \|  |  `~  |  }   |  -_  |  =+  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab | Tab  | ESC  |Enter |LCTRL |  {   |                    |   )  |  Tab |  Up  |  {[  |  ]}  |  \|  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|LShift| LGUI | LAlt |   _  |  (   |-------.    ,-------|BackSP| Left | Down |Right |   =  |Enter |
 * |------+------+------+------+------+------| CAPS  |    |  `~   |------+------+------+------+------+------|
 * |LCTRL |LCTRL | Home |Pg Up |Pg Dwn| End  |-------|    |-------|   B  |   V  |   C  |   X  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |Trans | LAlt |LGUI  | /Trans  /       \Space \  |Del   | TGUI |Trans |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SUPER] = LAYOUT(
  KC_POWER,  KC_PWR,   KC_SLEP,  KC_WAKE,  KC_NO,     KC_NO,                         KC_BSLS,  KC_GRV,   KC_RCBR,  KC_MINS,  KC_EQL,  KC_BSPC,
  KC_TAB,    KC_TAB,   KC_ESC,   KC_ENT,   KC_LCTRL,  KC_LCBR,                       KC_RPRN,  KC_TAB,   KC_UP,    KC_LBRC,  KC_RBRC, KC_TRNS,
  KC_LSFT,   KC_LSFT,  KC_LGUI,  KC_LALT,  KC_UNDS,   KC_LPRN,                       KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_EQL,  KC_ENT,
  KC_LCTL,   KC_LCTL,  KC_HOME,  KC_PGUP,  KC_PGDN,   KC_END,   KC_CAPS,  KC_GRV,    KC_B,     KC_V,     KC_C,     KC_X,     KC_Z,    KC_RSFT,
                                   KC_TRNS, KC_LALT, KC_LGUI, KC_TRNS,      KC_SPC, KC_DEL, KC_RGUI, KC_TRNS
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  | TAB  | XXXX |  (   |   )  | TAB  |                    | MUTE | VOLU |  Up  |_MOUSE|ENTER | CAPS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|LShift| DEL  |  [   |   ]  |  `~  |-------.    ,-------| VOLD | Left | Down |Right |RShift|_MOUSE|
 * |------+------+------+------+------+------|  BRID |    | BRIU  |------+------+------+------+------+------|
 * |LCTRL |LCTRL | MRWD | MPLY | MFFD | MSTP |-------|    |-------| End  |Pg Dwn|Pg Up | Home |RShift|RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |MS_BT2| LAlt | LGUI | /BackSP /       \Trans \  |Trans |Trans | XXXX |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,                         KC_F7,    KC_F8,    KC_F9,   KC_F10,      KC_F11,      KC_F12,
  KC_TAB,  KC_TAB,  KC_NO,   KC_LPRN,  KC_RPRN,  KC_TAB,                        KC_MUTE,  KC_VOLU,  KC_UP,   MO(_MOUSE),  KC_ENT,      KC_CAPS,
  KC_LSFT, KC_LSFT, KC_DEL,  KC_LBRC,  KC_RBRC,  KC_GRV,                        KC_VOLD,  KC_LEFT,  KC_DOWN, KC_RGHT,     KC_RSFT,     MO(_MOUSE),
  KC_LCTL, KC_LCTL, KC_MRWD, KC_MPLY,  KC_MFFD,  KC_MSTP,   KC_BRID, KC_BRIU,   KC_END,   KC_PGDN,  KC_PGUP, KC_HOME,     KC_RSFT,     KC_RSFT,
                               KC_NO, KC_LALT, KC_LGUI, KC_BSPC,      KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
),
/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |                    | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | XXXX | XXXX |MS_W_D| MS_U |MS_W_U| XXXX |                    | XXXX | XXXX |LShift|Trans | LGUI | XXXX |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | XXXX |MS_BT2| MS_L | MS_D | MS_R | XXXX |-------.    ,-------| XXXX | XXXX | XXXX | XXXX | XXXX |Trans |
 * |------+------+------+------+------+------|  XXXX |    | XXXX  |------+------+------+------+------+------|
 * | XXXX | XXXX |MS_W_R|MS_BT3|MS_W_L| XXXX |-------|    |-------| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | XXXX | XXXX | XXXX | / MS_BT1/       \ XXXX \  |Trans | XXXX | XXXX |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_MOUSE] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                     KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,   KC_NO,   KC_WH_D, KC_MS_U,  KC_WH_U,  KC_NO,                     KC_NO,  KC_NO,  KC_LSFT,  KC_TRNS,  KC_LGUI,  KC_NO,
  KC_NO,   KC_BTN2, KC_MS_L, KC_MS_D,  KC_MS_R,  KC_NO,                     KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
  KC_NO,   KC_NO,   KC_WH_R, KC_BTN3,  KC_WH_L,  KC_NO,    KC_NO, KC_NO,    KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  KC_NO, KC_NO, KC_NO, KC_BTN1,    KC_NO, KC_TRNS, KC_NO, KC_NO
)
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
//const char *read_keylog(void);
//const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
    // Paste the code from the previous step below this line!
    // 'DataDavD Logo', 128x32px
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x01, 0x01, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0x19, 0xf9, 0xf9, 0xf9, 0xe1, 0xe7, 0x07, 0xff, 0xff,
    0xff, 0x01, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0x01, 0xff, 0xff,
    0xff, 0x01, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0x61, 0x61, 0x67, 0x67, 0x67, 0x67, 0x07, 0x07, 0xff,
    0xff, 0x01, 0x01, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0xf9, 0xf9, 0xf9, 0xf9, 0x01, 0x01, 0xff,
    0xff, 0x01, 0x01, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0x19, 0xf9, 0xf9, 0xf9, 0xe1, 0xe7, 0x07, 0xff,
    0xff, 0xff, 0x01, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0x01, 0xff,
    0xff, 0xff, 0x01, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0x01, 0x01, 0xf9, 0xf9, 0xf9, 0xf9, 0x01, 0x01,
    0xff, 0xff, 0x01, 0x01, 0xf9, 0xf9, 0xf9, 0xf9, 0x19, 0x19, 0xf9, 0xf9, 0xe1, 0xe1, 0x07, 0x07,
    0x80, 0x80, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x98, 0x9f, 0x9f, 0x9f, 0x87, 0xe7, 0xe0, 0xff, 0xff,
    0xff, 0x80, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x99, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x80, 0xff, 0xff,
    0xff, 0x80, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x98, 0x98, 0x9e, 0x9e, 0x9e, 0x9e, 0x80, 0x80, 0xff,
    0xff, 0x80, 0x80, 0x9f, 0x9f, 0x9f, 0x9f, 0x99, 0x99, 0x9f, 0x9f, 0x9f, 0x9f, 0x80, 0x80, 0xff,
    0xff, 0x80, 0x80, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x98, 0x9f, 0x9f, 0x9f, 0x87, 0xe7, 0xe0, 0xff,
    0xff, 0xff, 0x80, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x99, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x80, 0xff,
    0xff, 0xff, 0xe0, 0xe7, 0x87, 0x9f, 0x9f, 0x9f, 0x98, 0x98, 0x9f, 0x9f, 0x87, 0x87, 0xe0, 0xe0,
    0xff, 0xff, 0x80, 0x80, 0x9f, 0x9f, 0x9f, 0x9f, 0x98, 0x98, 0x9f, 0x9f, 0x87, 0x87, 0xe0, 0xe0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff

  };

  oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_lfc_logo(void) {
  static const char PROGMEM my_lfc_logo[] = {
    // Paste the code from the previous step below this line!
    // 'YNWA', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 0xc3, 0x87,
    0x1f, 0x3f, 0x1f, 0x8f, 0xc3, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xf0, 0xe1,
    0xc3, 0x87, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xfc, 0xf0, 0x00, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x03, 0x81, 0x03, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0x1f, 0x00, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x87, 0xe1, 0xf0, 0xc0,
    0x07, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf1, 0xc3, 0x87, 0x1f, 0x1f, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x80, 0x03, 0x1f, 0x07, 0xc0, 0xf8, 0xff, 0xff, 0xfe, 0xf0, 0x81, 0x0f,
    0x07, 0x80, 0xf0, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x87, 0xe1, 0xf8, 0xf8, 0xf9, 0xf9, 0xf9, 0xf9,
    0xf9, 0xf8, 0xe0, 0x03, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0xfc, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

  };

  oled_write_raw_P(my_lfc_logo, sizeof(my_lfc_logo));
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_logo();
  } else {
    render_lfc_logo();
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
#endif
  }
  return true;
}

#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_SUPER (1 << 1)
#define L_RAISE (1 << 2)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_SUPER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Super");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
