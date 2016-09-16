#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include "simple_aes.h"

/* print how to use the program to stderr */
void print_usage(void) {
    fprintf(stderr,
            "Usage: "
            "./simple_aes <FILE> [KEY]\n"
            "FILE: the file to encrypt.\n"
            "KEY: the key to use; if not specified, "
            "attempt to read key from stdin.\n"
            "If no key is found, create a random key and print "
            "it to stdout once finished.");
}

/* handle different signals we receive */
void interrupt_handler(int signo) {
    if (signo == SIGINT) {
        fprintf(stderr, "Interrupt signal received\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char ** argv) {
    /* make sure we have at least 2 arguments, and not more than 3 */
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Invalid options!\n");
        print_usage();
        return EXIT_FAILURE;
    }

    /* register signal handler for SIGINT */
    if (signal(SIGINT, interrupt_handler) == SIG_ERR) {
        fprintf(stderr, "Can't register signal handler, aborting...\n");
        return EXIT_FAILURE;
    }

    /* placeholder 'functionality' */
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    if (argc == 3) printf("%s\n", argv[2]);

    while (1) {
        sleep(1);
    }

    return EXIT_SUCCESS;
}
