/* Copyright 2021 James Sa
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
#include "sm_td.h"

// Defines names for use in layer keycodes and the keymap
// enum layer_names {
//     _QWERTY,
// };

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     COLEMAK = SAFE_RANGE,   // colemak without home row modifier
//     COLEMAKm,               // colemak with home row modifier
//     DVORAK,
//     QWERTY
// };

#define _C(X) CTL_T(X)
#define _A(X) ALT_T(X)
#define _S(X) SFT_T(X)
#define _G(X) CMD_T(X)
#define FNBSPC LT(_FN, KC_BSPC)
#define PNSPC  LT(_PN, KC_SPC)
// macOS shortcut
#define MSNCTL  C(KC_UP)
#define WKSPLF  C(KC_LEFT)
#define WKSPRT  C(KC_RGHT)
#define COPY    G(KC_C)
#define PSTE    G(KC_V)
#define CUT     G(KC_X)
#define UNDO    G(KC_Z)
#define REDO    G(S(KC_Z))
#define SCNSHOT S(G(KC_4))
#define SPOTLT  G(KC_SPC)
#define ZOOMIN  G(KC_PPLS)  // command +
#define ZOOMOUT G(KC_PMNS)  // command -
#define ACTUAL  G(KC_0)
// window management utility
#define DIVVY   KC_F13

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS,
		KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_TRNS,
		KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,
		_______, KC_ESC, KC_SPC, KC_TAB, KC_ENT, KC_BSPC, KC_F13, _______
	),
	[1] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(LSFT(KC_Z)), LGUI(KC_V), LGUI(KC_C), LGUI(KC_X), LGUI(KC_Z), KC_TRNS,
		KC_TRNS, KC_LCTL, KC_LOPT, KC_LGUI, KC_LSFT, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_CAPS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS,
		_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______
	),
	[2] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(LSFT(KC_Z)), LGUI(KC_V), LGUI(KC_C), LGUI(KC_X), LGUI(KC_Z), KC_TRNS,
		KC_TRNS, KC_LCTL, KC_LOPT, KC_LGUI, KC_LSFT, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
		_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_BTN3, _______
	),
	[3] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_QUOT, KC_4, KC_5, KC_6, KC_EQL, KC_TRNS, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS,
		KC_TRNS, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		_______, KC_DOT, KC_0, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, _______
	),
	[4] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, LSFT(KC_LBRC), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_RBRC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, LSFT(KC_QUOT), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_EQUAL), KC_TRNS, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS,
		KC_TRNS, LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_BSLS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		_______, LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS), KC_TRNS, KC_TRNS, KC_TRNS, _______
	),
	[5] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_LCTL, KC_LOPT, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS, KC_TRNS,
		_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______
	),
	[6] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_F12, KC_F7, KC_F8, KC_F9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_F11, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_TRNS, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS,
		KC_TRNS, KC_F10, KC_F1, KC_F2, KC_F3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______
	)
};



void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    switch (keycode){
        case  KC_F17:
            if (record->event.pressed) {
                caps_word_on();
            }
            return false;   // override F17, otherwise caps word will be stopped.
    }
    return true;
}

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(KC_A, KC_LEFT_CTRL)
        SMTD_MT(KC_S, KC_LEFT_ALT)
        SMTD_MT(KC_D, KC_LEFT_GUI)
        SMTD_MT(KC_F, KC_LEFT_SHIFT)
        SMTD_MT(KC_SCLN, KC_LEFT_CTRL)
        SMTD_MT(KC_L, KC_LEFT_ALT)
        SMTD_MT(KC_K, KC_LEFT_GUI)
        SMTD_MT(KC_J, KC_LEFT_SHIFT)
        SMTD_LT(KC_SPC, 1)
        SMTD_LT(KC_TAB, 2)
        SMTD_LT(KC_BSPC, 3)
        SMTD_LT(KC_ENT, 4)
        SMTD_LT(KC_ESC, 5)
        SMTD_LT(KC_F13, 6)
    }
    return SMTD_RESOLUTION_UNHANDLED;
}
