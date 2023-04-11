#include <stdio.h>
#include "mirror256.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    uint8_t buffer[1024];
    size_t len;
    mirror256_context ctx;
    mirror256_init(&ctx);

    while ((len = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        mirror256_update(&ctx, buffer, len);
    }

    fclose(file);

    uint8_t digest[32];
    mirror256_final(&ctx, digest);

    printf("Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}
