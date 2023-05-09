#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>

#define palloc malloc
#define palloc0 malloc
#define repalloc realloc
#define pfree free
#define Assert assert
#define pg_strcasecmp strcasecmp
#define pvsnprintf vsnprintf
#define elog(...)
#define ereport(...)

#define AllocSetContextCreate(a,b,c) NULL
#define MemoryContextSwitchTo(a) NULL
#define MemoryContextDelete(a)
#define pg_attribute_printf(a,b)

#define CurrentMemoryContext 0

typedef int *MemoryContext;
typedef size_t Size;
