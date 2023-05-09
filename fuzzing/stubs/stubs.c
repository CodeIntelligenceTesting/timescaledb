#include "postgres.h"
#include "conn.h"

ssize_t ts_connection_write(Connection *conn, const char *buf, size_t writelen) {}

ssize_t ts_connection_read(Connection *conn, char *buf, size_t buflen) {}
