#include "keymap_common.h"
#include "action_layer.h"
#include "print.h"
#include "macro_strings.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(
        PAUS, DEL, 0, 9, 8, BSPC, 7, TAB, Q, 2, 1, \
        PGUP, VOLU, LBRC, MINS, RBRC, INS, Y, F5, F3, W, 4, F6, \
        HOME, CALC, P, O, I, U, R, E, ESC, 3, T, \
        SLCK, ENT, SCLN, L, K, BSLS, J, F, D, NUBS, A, LALT, \
        RGUI, A, SLSH, QUOT, LEFT, H, G, F4, S, ESC, LGUI, \
        END, RSFT, PGDN, NUHS,  DOT, COMM, M, V, C, X, Z, LSFT, \
        RCTL, RGHT, UP, DOWN, FN1, N, B, SPC, LCTL, \
        PSCR, VOLD, EQL, MPLY, MNXT, MUTE, MPRV, 5, F2, F1, GRV, 6), 

    /* 1: qwerty - for Windows (cmd becomes ctrl and right click button becomes windows button) */
    KEYMAP(
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, LGUI, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, LCTL, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS ),

    /* 2: FN1 (Replaces arrows with pagination, home and end and activates
               multimedia keys on top row).
     */
    KEYMAP(
        TRNS, TRNS, CAPS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, FN22, \
        TRNS, F12, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, VOLD, FN3, TRNS, TRNS, \
        TRNS, FN11, TRNS, TRNS, TRNS, TRNS, FN5, FN4, TRNS, TRNS, FN6, \
        TRNS, TRNS, TRNS, RGHT, UP, TRNS, DOWN, FN10, FN9, TRNS, FN7, FN2, \
        TRNS, TRNS, FN19, TRNS, HOME, LEFT, TRNS, VOLU, FN8, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, FN18, FN15, FN14, FN13, FN12, TRNS, \
        TRNS, END, PGUP, PGDN, TRNS, FN17, FN16, TRNS, TRNS, \
        TRNS, F11, TRNS, F9, F8, F10, F7, TRNS, MUTE, MPLY, TRNS, TRNS ),

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
  SHOW_LAYER,
  SHOW_HELP,
};
const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_DEFAULT_LAYER_SET(0),    // Default layer. Not used.
    [1] = ACTION_LAYER_TAP_KEY(2, KC_APP),  // FN1
    [2] = ACTION_LAYER_TOGGLE(1),  // FN2
    [3] = ACTION_MACRO(CTRL_OPTION_CMD_W),  // FN3
    [4] = ACTION_MACRO(CTRL_OPTION_CMD_E),  // FN4
    [5] = ACTION_MACRO(CTRL_OPTION_CMD_R),  // FN5
    [6] = ACTION_MACRO(CTRL_OPTION_CMD_T),  // FN6
    [7] = ACTION_MACRO(CTRL_OPTION_CMD_A),  // FN7
    [8] = ACTION_MACRO(CTRL_OPTION_CMD_S),  // FN8
    [9] = ACTION_MACRO(CTRL_OPTION_CMD_D),  // FN9
    [10] = ACTION_MACRO(CTRL_OPTION_CMD_F), // FN10
    [11] = ACTION_MACRO(SHOW_HELP), // FN11
    [12] = ACTION_MACRO(CTRL_OPTION_CMD_Z), // FN12
    [13] = ACTION_MACRO(CTRL_OPTION_CMD_X), // FN13
    [14] = ACTION_MACRO(CTRL_OPTION_CMD_C), // FN14
    [15] = ACTION_MACRO(CTRL_OPTION_CMD_V), // FN15
    [16] = ACTION_MACRO(CTRL_OPTION_CMD_B), // FN16
    [17] = ACTION_MACRO(CTRL_OPTION_CMD_N), // FN17
    [18] = ACTION_MACRO(CTRL_OPTION_CMD_M), // FN18
    [19] = ACTION_MACRO(SHOW_LAYER),        // FN19
    [20] = ACTION_LAYER_TOGGLE(1),   // FN20
    [21] = ACTION_MACRO(SELECT_IN_BRACES), // FN21
    [22] = ACTION_MACRO(SHOW_HELP),         // FN22
};

/*
 * Helper function to type a string
 * Automatically handles shift for uppercase and special characters
 */
void type_string(const char* str) {
    while (*str) {
        bool shift = false;
        uint8_t keycode = 0;

        char c = *str;

        // Lowercase letters
        if (c >= 'a' && c <= 'z') {
            keycode = KC_A + (c - 'a');
        }
        // Uppercase letters
        else if (c >= 'A' && c <= 'Z') {
            keycode = KC_A + (c - 'A');
            shift = true;
        }
        // Numbers
        else if (c >= '0' && c <= '9') {
            keycode = KC_1 + (c - '1');
            if (c == '0') keycode = KC_0;
        }
        // Special characters
        else {
            switch (c) {
                case '\n': keycode = KC_ENT; break;
                case ' ': keycode = KC_SPC; break;
                case '!': keycode = KC_1; shift = true; break;
                case '@': keycode = KC_2; shift = true; break;
                case '#': keycode = KC_3; shift = true; break;
                case '$': keycode = KC_4; shift = true; break;
                case '%': keycode = KC_5; shift = true; break;
                case '^': keycode = KC_6; shift = true; break;
                case '&': keycode = KC_7; shift = true; break;
                case '*': keycode = KC_8; shift = true; break;
                case '(': keycode = KC_9; shift = true; break;
                case ')': keycode = KC_0; shift = true; break;
                case '-': keycode = KC_MINS; break;
                case '_': keycode = KC_MINS; shift = true; break;
                case '=': keycode = KC_EQL; break;
                case '+': keycode = KC_EQL; shift = true; break;
                case '[': keycode = KC_LBRC; break;
                case '{': keycode = KC_LBRC; shift = true; break;
                case ']': keycode = KC_RBRC; break;
                case '}': keycode = KC_RBRC; shift = true; break;
                case '\\': keycode = KC_BSLS; break;
                case '|': keycode = KC_BSLS; shift = true; break;
                case ';': keycode = KC_SCLN; break;
                case ':': keycode = KC_SCLN; shift = true; break;
                case '\'': keycode = KC_QUOT; break;
                case '"': keycode = KC_QUOT; shift = true; break;
                case ',': keycode = KC_COMM; break;
                case '<': keycode = KC_COMM; shift = true; break;
                case '.': keycode = KC_DOT; break;
                case '>': keycode = KC_DOT; shift = true; break;
                case '/': keycode = KC_SLSH; break;
                case '?': keycode = KC_SLSH; shift = true; break;
                case '`': keycode = KC_GRV; break;
                case '~': keycode = KC_GRV; shift = true; break;
            }
        }

        if (keycode) {
            if (shift) {
                register_code(KC_LSFT);
            }
            register_code(keycode);
            unregister_code(keycode);
            if (shift) {
                unregister_code(KC_LSFT);
            }
        }

        str++;
    }
}

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
          if (record->event.pressed) {
              type_string(MACRO_EMAIL_WORK);
          }
          return MACRO_NONE;
        case CTRL_OPTION_CMD_X:
          if (record->event.pressed) {
              type_string(MACRO_ADDRESS);
          }
          return MACRO_NONE;
        case CTRL_OPTION_CMD_C:
          if (record->event.pressed) {
              type_string(MACRO_CONSOLE_LOG);
              // Move cursor back 2 positions and enter paste mode
              return MACRO( T(LEFT), T(LEFT), T(ESC), T(P), END );
          }
          return MACRO_NONE;
        case CTRL_OPTION_CMD_V:
          if (record->event.pressed) {
              type_string(MACRO_EMAIL_PERSONAL);
          }
          return MACRO_NONE;
        case CTRL_OPTION_CMD_B:
          if (record->event.pressed) {
              type_string(MACRO_PHONE_OTHER);
          }
          return MACRO_NONE;
        case CTRL_OPTION_CMD_N:
          if (record->event.pressed) {
              type_string(MACRO_PHONE_PERSONAL);
          }
          return MACRO_NONE;
        case CTRL_OPTION_CMD_M:
          if (record->event.pressed) {
              type_string(MACRO_PHONE_INTL);
          }
          return MACRO_NONE;
        case SELECT_IN_BRACES:
          return (record->event.pressed ?
              MACRO( T(ESC), T(ESC), T(V), T(A), T(F), END ) :
              MACRO_NONE);
        case SHOW_LAYER:
          if (record->event.pressed) {
              // Check both layer_state and default_layer_state
              xprintf("SHOW_LAYER pressed\n");
              xprintf("  default_layer_state: %lu\n", default_layer_state);
              xprintf("  layer_state: %lu\n", layer_state);

              // Check if layer 1 (Windows) is active in layer_state
              if (layer_state & (1UL << 1)) {
                  // Type "Layer 1 (win)"
                  xprintf("  Typing: Layer 1 (win)\n");
                  type_string("Layer 1 (win)");
              } else {
                  // Type "Layer 0"
                  xprintf("  Typing: Layer 0\n");
                  type_string("Layer 0");
              }
          }
          return MACRO_NONE;
        case SHOW_HELP:
          if (record->event.pressed) {
              xprintf("SHOW_HELP pressed\n");
              // Type help text showing all macro shortcuts
              type_string("=== Keyboard Macros Help ===\n");
              type_string("FN + CALC  = Show this help\n");
              type_string("FN + /  = Show current layer\n");
              type_string("FN + WIN  = Toggle Windows layer\n");
              type_string("\n--- Text Macros ---\n");
              type_string("FN + Z  = Work email\n");
              type_string("FN + X  = Address\n");
              type_string("FN + V  = Personal email\n");
              type_string("FN + B  = Personal number\n");
              type_string("FN + N  = Phone (personal)\n");
              type_string("FN + M  = Phone with +46\n");
          }
          return MACRO_NONE;
    }
    return MACRO_NONE;
}