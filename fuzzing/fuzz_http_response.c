#include <assert.h>
#include <cifuzz/cifuzz.h>

#include "http.h"

FUZZ_TEST_SETUP() {
    // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
    // Create an HttpResponseState
    HttpResponseState *state = ts_http_response_state_create();

    // Obtain the buffer pointer
    char *parse_buffer;
    ssize_t parse_buffer_size = 0;
    parse_buffer = ts_http_response_state_next_buffer(state, &parse_buffer_size);

    // Write fuzzer data
    if(size < parse_buffer_size)
        parse_buffer_size = size;
    memcpy(parse_buffer, data, parse_buffer_size);

    // Do the parsing. This is what we want to test.
    ts_http_response_state_parse(state, parse_buffer_size);
    ts_http_response_state_is_done(state);

    // Free resources
    ts_http_response_state_destroy(state);
    HttpHeader *header = ts_http_response_state_headers(state);
    while(header != NULL) {
        HttpHeader *tmp = header;
        header = header->next;
        free(tmp->name);
        free(tmp->value);
        free(tmp);
    }
    free(state);
}
