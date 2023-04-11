#include "mirror256.h"
#include <string.h>
#include <math.h>

// Helper functions
void init_standard_state(uint8_t state[][MIRROR256_DEFAULT_SIZE / 4]) {
    for (int i = 0; i < MIRROR256_DEFAULT_DEPTH; i++) {
        for (int j = 0; j < MIRROR256_DEFAULT_SIZE / 4; j++) {
            state[i][j] = (uint8_t)(firstPrimesCubicRootDecRep[i * MIRROR256_DEFAULT_SIZE / 4 + j] * 256);
        }
    }
}

void init_last_hashes(uint8_t last_hashes[][MIRROR256_DEFAULT_SIZE / 4]) {
    memset(last_hashes, 0, MIRROR256_DEFAULT_DEPTH * MIRROR256_DEFAULT_SIZE / 4);
}

void mirror256_init(mirror256_context *ctx) {
    memset(ctx->buffer, 0, sizeof(ctx->buffer));
    ctx->counter = 0;
    ctx->depth = MIRROR256_DEFAULT_DEPTH;
    ctx->size = MIRROR256_DEFAULT_SIZE;

    // Initialize standard state
    uint8_t standard_state[MIRROR256_DEFAULT_DEPTH][MIRROR256_DEFAULT_SIZE / 4];
    init_standard_state(standard_state);

    // Initialize last_hashes with init_last_hashes logic
    init_last_hashes(ctx->last_hashes);

    // Copy standard state to last_hashes
    for (int i = 0; i < ctx->depth; i++) {
        memcpy(ctx->last_hashes[i], standard_state[i], MIRROR256_DEFAULT_SIZE / 4);
    }
}

void _mirror256_process(mirror256_context *ctx, const uint8_t *data) {
    for (int i = 0; i < MIRROR256_DEFAULT_SIZE / 8; i++) {
        uint8_t byte = data[i];
        for (int j = 0; j < 8; j++) {
            uint8_t bit = (byte >> j) & 1;
            if (bit) {
                for (int k = 0; k < MIRROR256_DEFAULT_SIZE / 4; k++) {
                    ctx->last_hashes[j][k] ^= ctx->buffer[k];
                }
            }
        }

        ctx->counter++;
        if (ctx->counter >= ctx->depth) {
            ctx->counter = 0;
            for (int j = 0; j < MIRROR256_DEFAULT_SIZE / 4; j++) {
                ctx->buffer[j] = 0;
                for (int k = 0; k < MIRROR256_DEFAULT_DEPTH; k++) {
                    ctx->buffer[j] ^= ctx->last_hashes[k][j];
                }
            }
        }
    }
}

void mirror256_update(mirror256_context *ctx, const uint8_t *data, size_t len) {
    size_t buffer_pos = ctx->counter % (MIRROR256_DEFAULT_SIZE / 8);
    while (len > 0) {
        size_t block_remain = MIRROR256_DEFAULT_SIZE / 8 - buffer_pos;
        size_t chunk_size = (len < block_remain) ? len : block_remain;

        memcpy(&ctx->buffer[buffer_pos], data, chunk_size);
        buffer_pos += chunk_size;
        data += chunk_size;
        len -= chunk_size;

        if (buffer_pos == MIRROR256_DEFAULT_SIZE / 8) {
            _mirror256_process(ctx, ctx->buffer);
            buffer_pos = 0;
        }
    }

    ctx->counter += buffer_pos;
}

void mirror256_final(mirror256_context *ctx, uint8_t *digest) {
    // Process the remaining buffer data and compute the final hash value using the digest() logic from the Python code.
    // Then, store the result in the "digest" parameter.
}
