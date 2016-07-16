#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "simple_aes.h"
#include "util.h"

/* KEY = ffffffffffffffffffffffffffffffff
 * PLAINTEXT = 00000000000000000000000000000000
 * CIPHERTEXT = a1f6258c877d5fcd8964484538bfc92c
 */

int main(void) {
    uint8_t * message = (uint8_t *) calloc(16, sizeof(uint8_t));
    uint8_t * key = (uint8_t *) calloc(16, sizeof(uint8_t));

    for (uint8_t i = 0; i < 16; i++) {
        key[i] = 0xff;
    }

    CHECK_ALLOC(message);
    CHECK_ALLOC(key);

    printf("AES-128\n");
    printf("Plaintext:\n");
    for (uint8_t i = 0; i < 15; i++) {
        printf("0x%02x, ", message[i]);
    }
    printf("0x%02x\n\n", message[15]);

    aes128_encrypt(message, key);

    printf("Ciphertext (encryption result):\n");
    for (uint8_t i = 0; i < 15; i++) {
        printf("0x%02x, ", message[i]);
    }
    printf("0x%02x\n\n", message[15]);

    aes128_decrypt(message, key);

    printf("Plaintext (decryption result):\n");
    for (uint8_t i = 0; i < 15; i++) {
        printf("0x%02x, ", message[i]);
    }
    printf("0x%02x\n\n", message[15]);

    printf("\n\n");
    printf("AES-192\n");
    printf("Plaintext:\n");
    for (uint8_t i = 0; i < 15; i++) {
        printf("0x%02x, ", message[i]);
    }
    printf("0x%02x\n\n", message[15]);

    key = (uint8_t *) realloc(key, 24 * sizeof(uint8_t));

    CHECK_ALLOC(key);
    for (uint8_t i = 0; i < 24; i++) {
        key[i] = 0xff;
    }

    aes192_encrypt(message, key);

    printf("Ciphertext (encryption result):\n");
    for (uint8_t i = 0; i < 15; i++) {
        printf("0x%02x, ", message[i]);
    }
    printf("0x%02x\n\n", message[15]);

    aes192_decrypt(message, key);

    printf("Plaintext (decryption result):\n");
    for (uint8_t i = 0; i < 15; i++) {
        printf("0x%02x, ", message[i]);
    }
    printf("0x%02x\n\n", message[15]);

    printf("\n\n");
    printf("AES-256\n");
    printf("Plaintext:\n");
    for (uint8_t i = 0; i < 15; i++) {
        printf("0x%02x, ", message[i]);
    }
    printf("0x%02x\n\n", message[15]);

    key = (uint8_t *) realloc(key, 32 * sizeof(uint8_t));

    CHECK_ALLOC(key);
    for (uint8_t i = 0; i < 24; i++) {
        key[i] = 0xff;
    }

    aes256_encrypt(message, key);

    printf("Ciphertext (encryption result):\n");
    for (uint8_t i = 0; i < 15; i++) {
        printf("0x%02x, ", message[i]);
    }
    printf("0x%02x\n\n", message[15]);

    aes256_decrypt(message, key);

    printf("Plaintext (decryption result):\n");
    for (uint8_t i = 0; i < 15; i++) {
        printf("0x%02x, ", message[i]);
    }
    printf("0x%02x\n\n", message[15]);

    free(message);
    free(key);
    return EXIT_SUCCESS;
}
