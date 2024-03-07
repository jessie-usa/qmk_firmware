/* Copyright 2022 DOIO
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
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

/*
 * JESSIE USA IN THE HOUUUUUUUSE
 * Aright mothafuckas.  Making my shit hot.  Step aside.  Please clap.
 *
 * Layer 0 is gonna be for fuckin around doing whatever.  Gooning etc
 *
 * Layer 1 is for REAPER [ GANG GANG MOTHER FUCKERS ]
 *
 * Layer 2 ... more Reaps?
 *
 * Layer 3 dude i'm only using this for Reaper lol
*/

#include QMK_KEYBOARD_H

// OLED animation
#include "lib/layer_status/layer_status.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _BASE,
    _FN,
    _FN1,
    _FN2
};

// enum layer_keycodes { };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(

    /*                                                                                                                              */


                G(KC_W),                     G(KC_COMMA),              G(KC_M),             S(KC_SLASH),          S(C(KC_D)),

    /*                                                                                                                              */


                KC_1,                        G(C(S(KC_T))),            G(C(S(KC_S))),       G(C(S(KC_R))),     TO(_FN),

    /*                                                                                                                              */


                G(A(S(KC_1))),              G(S(KC_Z)),                  G(A(C(S(KC_X)))),          G(KC_Z),          G(KC_F10),

    /*                                                                                                                              */


                KC_P,                       S(C(KC_R)),                KC_S         ,       KC_Z

    ),
    [_FN] = LAYOUT(

    /*                                                                                                                              */


                G(S(C(KC_I)))      ,         _______         ,         _______      ,       A(S(KC_2)),       S(C(KC_D)),

    /*                                                                                                                              */


                S(A(KC_X))         ,         _______         ,         _______      ,       S(A(KC_A)),       TO(_FN2),

    /*                                                                                                                              */


                KC_A               ,         _______         ,         S(KC_W)      ,       G(KC_PGDN),       TO(_FN2),

    /*                                                                                                                              */


                _______            ,         S(C(KC_R))      ,         KC_S         ,       KC_Z

    ),
    [_FN1] = LAYOUT(

    /*                                                                                                                              */


                G(S(C(KC_I)))      ,         _______         ,         _______      ,       A(S(KC_2)),       S(C(KC_D)),

    /*                                                                                                                              */


                S(A(KC_X))         ,         _______         ,         _______      ,       S(A(KC_A)),       TO(_FN2),

    /*                                                                                                                              */


                KC_A               ,         _______         ,         S(KC_W)      ,       G(KC_PGDN),       TO(_FN2),

    /*                                                                                                                              */


                _______            ,         S(C(KC_R))      ,         KC_S         ,       KC_Z

    ),
    [_FN2] = LAYOUT(

    /*                                                                                                                              */


                G(S(C(KC_I)))      ,         _______         ,         _______      ,       A(S(KC_2)),       S(C(KC_D)),

    /*                                                                                                                              */


                S(A(KC_X))         ,         _______         ,         _______      ,       S(A(KC_A)),       TO(_FN2),

    /*                                                                                                                              */


                KC_A               ,         _______         ,         S(KC_W)      ,       G(KC_PGDN),       TO(_FN2),

    /*                                                                                                                              */


                _______            ,         S(C(KC_R))      ,         KC_S         ,       KC_Z

    ),
};

#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

    [_BASE] =
    {
                ENCODER_CCW_CW(
                    G(A(S(KC_MINUS))),
                    G(A(S(KC_EQUAL)))
                ),
                ENCODER_CCW_CW(
                    KC_PGDN,
                    KC_PGUP
                ),
                ENCODER_CCW_CW(
                    G(KC_F11),
                    G(KC_F12)
                )
    },
    [_FN] =
    {
                ENCODER_CCW_CW(
                    KC_TRNS,
                    KC_TRNS
                ),
                ENCODER_CCW_CW(
                    KC_TRNS,
                    KC_TRNS
                ),
                ENCODER_CCW_CW(
                    KC_TRNS,
                    KC_TRNS
                )
    },
    [_FN1] =
    {
                ENCODER_CCW_CW(
                    KC_TRNS,
                    KC_TRNS
                ),
                ENCODER_CCW_CW(
                    KC_TRNS,
                    KC_TRNS
                ),
                ENCODER_CCW_CW(
                    G(A(LSFT(KC_P1))),
                    G(A(LSFT(KC_P2)))
                )
    },
    [_FN2] =
    {
                ENCODER_CCW_CW(
                    KC_TRNS,
                    KC_TRNS
                ),
                ENCODER_CCW_CW(
                    KC_TRNS,
                    KC_TRNS
                ),
                ENCODER_CCW_CW(
                    G(A(LSFT(KC_P4))),
                    G(A(LSFT(KC_P5)))
                )
    },
};
#endif
