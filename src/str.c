#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "str.h"

char *string_duplicate(const char *str,
                       const char *str_end)
{
    assert(str);

    if (str_end != NULL && str > str_end) {
        return NULL;
    }

    const size_t n = str_end == NULL ? strlen(str) : (size_t) (str_end - str);
    char *dup_str = calloc(1, sizeof(char) * (n + 1));
    if (dup_str == NULL) {
        return NULL;
    }

    memcpy(dup_str, str, n);
    dup_str[n] = '\0';

    return dup_str;
}

char *trim_endline(char *s)
{
    const size_t n = strlen(s);

    if (n == 0) {
        return s;
    }

    if (s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }

    return s;
}

char *string_append(char *prefix, const char *suffix)
{
    assert(suffix);

    if (prefix == NULL) {
        return string_duplicate(suffix, NULL);
    }

    prefix = realloc(prefix, strlen(prefix) + strlen(suffix) + 1);
    return strcat(prefix, suffix);
}
