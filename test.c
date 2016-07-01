#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "simple_aes.h"

/*
KEY = ffffffffffffffffffffffffffffffff
PLAINTEXT = 00000000000000000000000000000000
CIPHERTEXT = a1f6258c877d5fcd8964484538bfc92c
*/
int main(void) {
    uint8_t * message = (uint8_t *) calloc(16, sizeof(uint8_t));
    uint8_t * key = (uint8_t *) calloc(16, sizeof(uint8_t));

    /* set key and message to something simple */
    for (uint8_t i = 0; i < 16; i++) {
        key[i] = 0xff;
        message[i] = 0x00;
    }

    printf("Message to encrypt:\n");
    for (uint8_t i = 0; i < 16; i++) {
        printf("%02x ", message[i]);
    }
    printf("\n\n");

    aes128_encrypt(message, key);

    printf("Encrypted message (ciphertext):\n");
    for (uint8_t i = 0; i < 16; i++) {
        printf("%02x ", message[i]);
    }
    printf("\n\n");

    aes128_decrypt(message, key);

    printf("Decrypted ciphertext:\n");
    for (uint8_t i = 0; i < 16; i++) {
        printf("%02x ", message[i]);
    }
    printf("\n");

    free(message);
    free(key);
    return EXIT_SUCCESS;
}
