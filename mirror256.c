#include "mirror256.h"
#include <string.h>
#include <math.h>

#include "mirror256.h"
#include <string.h>
#include <math.h>

// Helper functions
void init_standard_state(uint8_t state[][MIRROR256_DEFAULT_SIZE / 4]) {
    // Implement the initStandardState logic from the Python code here.
}

void init_last_hashes(uint8_t last_hashes[][MIRROR256_DEFAULT_SIZE / 4]) {
    // Implement the initLastHashes logic from the Python code here.
}

void mirror256_init(mirror256_context *ctx) {
    memset(ctx->buffer, 0, sizeof(ctx->buffer));
    ctx->counter = 0;
    ctx->depth = MIRROR256_DEFAULT_DEPTH;
    ctx->size = MIRROR256_DEFAULT_SIZE;

    // Initialize standard state
    uint8_t standard_state[MIRROR256_DEFAULT_DEPTH][MIRROR256_DEFAULT_SIZE / 4];
    init_standard_state(standard_state);

    // Initialize last_hashes with initLastHashes logic
    init_last_hashes(ctx->last_hashes);

    // Copy standard state to last_hashes
    for (int i = 0; i < ctx->depth; i++) {
        memcpy(ctx->last_hashes[i], standard_state[i], MIRROR256_DEFAULT_SIZE / 4);
    }
}

void mirror256_update(mirror256_context *ctx, const uint8_t *data, size_t len) {
    size_t buffer_len = ctx->counter % 32;
    size_t available = 32 - buffer_len;

    while (len > 0) {
        size_t to_copy = len < available ? len : available;
        memcpy(ctx->buffer + buffer_len, data, to_copy);
        data += to_copy;
        len -= to_copy;
        buffer_len += to_copy;

        if (buffer_len == 32) {
            // Process the buffer using _mirror256_process() logic from the Python code.
            buffer_len = 0;
        }

        available = 32 - buffer_len;
    }

    ctx->counter += len;
}

void mirror256_final(mirror256_context *ctx, uint8_t *digest) {
    // Process the remaining buffer data and compute the final hash value using the digest() logic from the Python code.
    // Then, store the result in the "digest" parameter.
}
