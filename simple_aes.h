#pragma once

#include <stdint.h>

void aes128_encrypt(uint8_t * state, uint8_t * key);
void aes128_decrypt(uint8_t * state, uint8_t * key);
