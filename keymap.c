#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _MEDIA 2
#define _Numpad 3
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  Media,
  Numpad,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower | Bksp |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP ( \
  KC_TAB,  KC_Q,    KC_W,    TD_E_ACCENT,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
  KC_LCTL, KC_LALT, KC_LEFT, KC_RGHT, LOWER,   GUI_T(KC_BSPC), KC_SPC,  RAISE,   KC_UP,   KC_DOWN, KC_RGUI, KC_ENT \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower | Bksp |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = KEYMAP ( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    TD_E_ACCENT,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL, KC_LALT, KC_LEFT, KC_RGHT, LOWER,   GUI_T(KC_BSPC), KC_SPC,  RAISE,   KC_UP,   KC_DOWN, KC_RGUI, KC_ENT \
),

/* MEDIA
 * ,-----------------------------------------------------------------------------------.
 * |   |  |   !  |   "  |   @  |   $  |   %  |   &  |   ^  |   *  |   ?  |   '  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   (  |   )  |      | Undo | Copy |      | Vol+ |  Ins | Home | PgUp |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   [  |   ]  | Menu | Find |Paste | Mute | Vol- |  Del |  End | PgDN | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |Lower | Bksp |Space |Raise |  Up  | Down |  GUI |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = KEYMAP ( \
  KC_NUBS,  KC_EXLM, KC_DQT, KC_AT,  KC_DLR,    KC_PERC,    KC_AMPR,    KC_CIRC,    KC_ASTR,    KC_QUES,    KC_QUOT,    KC_NUHS, \
  KC_ESC,  KC_LPRN,    KC_RPRN,    _______,    KC_UNDO,    KC_COPY,    _______,    KC_VOLU,    KC_VOLD,    KC_HOME,    KC_PGUP,    _______, \
  KC_LSFT, KC_LBRC, KC_RBRC,    KC_MENU,    KC_FIND,    KC_PASTE,    KC_MUTE,    KC_VOLD,    KC_DEL,    KC_END,    KC_PGDN,    KC_RSFT, \
  KC_LCTL, _______, _______, _______, LOWER,   GUI_T(KC_BSPC), KC_SPC,  RAISE,   KC_UP,   KC_DOWN, KC_RGUI, KC_ENT \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   /  |   7  |   8  |   9  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   *  |   4  |   5  |   6  |   0  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   -  |   1  |   2  |   3  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |LOWER |RAISE |   +  |   ,  |   .  |      |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = KEYMAP ( \
  _______, _______, _______, _______, _______,  _______, _______, KC_PSLS, KC_P7, KC_P8, KC_P9, _______, \
  KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PAST, KC_P4, KC_P5, KC_P6, KC_P0, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PMNS, KC_P1, KC_P2, KC_P3, KC_PENT, \
  _______, _______, _______, _______,  _______, LOWER,  RAISE,  KC_PPLS, KC_PCMM, KC_PDOT, _______, KC_ENT \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Reset|      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |RGB ON| MODE | HUE+ | HUE- | SAT+ | SAT- | VAL+ | VAL- |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = KEYMAP ( \
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12 , \
  _______, RESET,   _______, _______, _______, AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case MEDIA:
       if (record->event.pressed) {
        layer_on(_MEDIA);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_MEDIA);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_NUMPAD);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
  return true;
}

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case MEDIA:
      if (record->event.pressed) {
        layer_on(_MEDIA);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_MEDIA);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_NUMPAD);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

//Tap Dance Declarations
enum {

  TD_E_ACCENT

};

//Tap Dance Definitions


void accent_e (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count = 2) {
	unicode_input_start();
    register_hex(0x00e8);
    unicode_input_finish();
  } else {
    register_code(KC_E);
    unregister_code(KC_E);
  }
}

void accent_e (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count = 3) {
	unicode_input_start();
    register_hex(0x00e9);
    unicode_input_finish();
  } else {
    register_code(KC_E);
    unregister_code(KC_E);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_E_ACCENT] = ACTION_TAP_DANCE_FN (accent_e)
};

#ifdef UNICODE_ENABLE
    QK_UNICODE            = 0x8000,
    QK_UNICODE_MAX        = 0xFFFF,
#endif
#ifdef UNICODEMAP_ENABLE
    QK_UNICODE_MAP        = 0x8000,
    QK_UNICODE_MAP_MAX    = 0x83FF,
#endif

