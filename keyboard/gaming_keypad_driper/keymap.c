#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
KEYMAP(
        GRV,  1, 2, 3, 4, 5, 6, BSPC, \
        TAB,  Q, W, E, R, T, Y, U,
        LSFT, A, S, D, F, G, H, J,
        LALT, Z, X, C, FN1, \
        SPC, \
        RCTL, \
        LGUI), \

    /* 2: FN1 */
KEYMAP(
        ESC, 1, 2, 3, 4, 5, 6, 7, \
        Q, W, E, R, T, Y, U, I,
        A, S, D, F, G, H, J, K, \
        Z, X, C, V, FN1, \
        LALT, \
        LGUI, \
        LCTL), \
};

enum macro_id {
  CTRL_OPTION_CMD_Q,
  CTRL_OPTION_CMD_W,
  CTRL_OPTION_CMD_E,
  CTRL_OPTION_CMD_R,
  CTRL_OPTION_CMD_T,
  CTRL_OPTION_CMD_A,
  CTRL_OPTION_CMD_S,
  CTRL_OPTION_CMD_D,
  CTRL_OPTION_CMD_F,
  CTRL_OPTION_CMD_G,
  CTRL_OPTION_CMD_Z,
  CTRL_OPTION_CMD_X,
  CTRL_OPTION_CMD_C,
  CTRL_OPTION_CMD_V,
  CTRL_OPTION_CMD_B,
  CTRL_OPTION_CMD_N,
  CTRL_OPTION_CMD_M,
  SELECT_IN_BRACES,
};
const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_DEFAULT_LAYER_SET(0),    // Default layer. Not used.
    [1] = ACTION_LAYER_TAP_KEY(1, KC_APP),  // FN1
    [2] = ACTION_MACRO(CTRL_OPTION_CMD_Q),  // FN2
    [3] = ACTION_MACRO(CTRL_OPTION_CMD_W),  // FN3
    [4] = ACTION_MACRO(CTRL_OPTION_CMD_E),  // FN4
    [5] = ACTION_MACRO(CTRL_OPTION_CMD_R),  // FN5
    [6] = ACTION_MACRO(CTRL_OPTION_CMD_T),  // FN6
    [7] = ACTION_MACRO(CTRL_OPTION_CMD_A),  // FN7
    [8] = ACTION_MACRO(CTRL_OPTION_CMD_S),  // FN8
    [9] = ACTION_MACRO(CTRL_OPTION_CMD_D),  // FN9
    [10] = ACTION_MACRO(CTRL_OPTION_CMD_F), // FN10
    [11] = ACTION_MACRO(CTRL_OPTION_CMD_G), // FN11
    [12] = ACTION_MACRO(CTRL_OPTION_CMD_Z), // FN12
    [13] = ACTION_MACRO(CTRL_OPTION_CMD_X), // FN13
    [14] = ACTION_MACRO(CTRL_OPTION_CMD_C), // FN14
    [15] = ACTION_MACRO(CTRL_OPTION_CMD_V), // FN15
    [16] = ACTION_MACRO(CTRL_OPTION_CMD_B), // FN16
    [17] = ACTION_MACRO(CTRL_OPTION_CMD_N), // FN17
    [18] = ACTION_MACRO(CTRL_OPTION_CMD_M), // FN18
    [19] = ACTION_LAYER_TOGGLE(1),   // FN19
    [20] = ACTION_MACRO(SELECT_IN_BRACES), // FN20
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case CTRL_OPTION_CMD_Q:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(Q), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_W:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(W), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_E:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(E), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_R:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(R), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_T:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(T), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_A:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(A), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_S:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(S), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_D:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(D), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_F:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(F), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_G:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(G), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_Z:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(Z), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_X:
          return (record->event.pressed ?
              MACRO( D(LGUI), D(LALT), D(LCTL), T(X), U(LGUI), U(LALT), U(LCTL), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_C:
          return (record->event.pressed ?
              MACRO( T(Y), T(O), T(C), T(O), T(N), T(S), T(O), T(L), T(E), T(DOT), T(L), T(O), T(G), D(LSFT), T(9), T(0), U(LSFT), T(SCLN), T(LEFT), T(LEFT), T(ESC), T(P), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_V:
          return (record->event.pressed ?
              MACRO( T(L), T(U), T(K), T(A), T(S), T(DOT), T(M), T(A), T(C), T(I), T(U), T(L), T(I), T(S), D(LSFT), T(2), U(LSFT), T(G), T(M), T(A), T(I), T(L), T(DOT), T(C), T(O), T(M), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_B:
          return (record->event.pressed ?
              MACRO( T(1), T(9), T(8), T(6), T(0), T(6), T(1), T(4), T(8), T(3), T(9), T(6), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_N:
          return (record->event.pressed ?
              MACRO( T(PPLS), T(4), T(6), T(7), T(6), T(0), T(0), T(1), T(6), T(5), T(3), T(6), END ) :
              MACRO_NONE);
        case CTRL_OPTION_CMD_M:
          return (record->event.pressed ?
              MACRO( T(0), T(7), T(6), T(0), T(0), T(1), T(6), T(5), T(3), T(6), END ) :
              MACRO_NONE);
        case SELECT_IN_BRACES:
          return (record->event.pressed ?
              MACRO( T(ESC), T(ESC), T(V), T(A), T(F), END ) :
              MACRO_NONE);
    }
    return MACRO_NONE;
}