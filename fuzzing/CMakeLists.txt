# Fuzz test for http_response.c
add_fuzz_test(fuzz_http_response
    "fuzz_http_response.c"
    "stubs/stubs.c"
    "stubs/stringinfo.c"
    "${CMAKE_SOURCE_DIR}/src/net/http.c"
    "${CMAKE_SOURCE_DIR}/src/net/http_request.c"
    "${CMAKE_SOURCE_DIR}/src/net/http_response.c"
)
target_include_directories(fuzz_http_response PRIVATE
    "stubs"
    "${CMAKE_SOURCE_DIR}/src/net"
)