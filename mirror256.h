#ifndef MIRROR256_H
#define MIRROR256_H

#include <stdint.h>
#include <stdlib.h>

typedef struct mirror256_context {
    uint8_t last_hashes[64][32];
    uint8_t buffer[32];
    size_t counter;
    uint8_t hashed[32];
} mirror256_context;

void mirror256_init(mirror256_context *ctx);
void mirror256_update(mirror256_context *ctx, const uint8_t *data, size_t len);
void mirror256_final(mirror256_context *ctx, uint8_t *digest);

#endif // MIRROR256_H
