#pragma once

#include <stdint.h>

void aes128_encrypt(uint8_t * state, uint8_t * key);
void aes128_decrypt(uint8_t * state, uint8_t * key);

void aes192_encrypt(uint8_t * state, uint8_t * key);
void aes192_decrypt(uint8_t * state, uint8_t * key);

void aes256_encrypt(uint8_t * state, uint8_t * key);
void aes256_decrypt(uint8_t * state, uint8_t * key);
