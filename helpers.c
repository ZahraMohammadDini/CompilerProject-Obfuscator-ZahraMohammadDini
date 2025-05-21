#include <stdio.h>
#include <string.h>
#include "helpers.h"

void replace_word(char *line, const char *old, const char *new) {
    char buffer[1024];
    char *pos;

    while ((pos = strstr(line, old)) != NULL) {
        buffer[0] = '\0';
        strncat(buffer, line, pos - line);
        strcat(buffer, new);
        strcat(buffer, pos + strlen(old));
        strcpy(line, buffer);
    }
}
