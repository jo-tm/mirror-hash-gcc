#ifndef MIRROR256_H
#define MIRROR256_H

#include <stddef.h>
#include <stdint.h>

#define MIRROR256_DEFAULT_DEPTH 64
#define MIRROR256_DEFAULT_SIZE 256

// Define firstPrimesCubicRootDecRep here
static const float firstPrimesCubicRootDecRep[] = {
    // Your firstPrimesCubicRootDecRep values here
};

typedef struct {
    uint8_t buffer[MIRROR256_DEFAULT_SIZE / 8];
    uint64_t counter;
    uint8_t depth;
    uint8_t size;
    uint8_t last_hashes[MIRROR256_DEFAULT_DEPTH][MIRROR256_DEFAULT_SIZE / 4];
} mirror256_context;

void mirror256_init(mirror256_context *ctx);
void mirror256_update(mirror256_context *ctx, const uint8_t *data, size_t len);
void mirror256_final(mirror256_context *ctx, uint8_t *digest);

#endif // MIRROR256_H
