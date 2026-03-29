#include <internal/syscall.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int puts(const char *str) {
    if (str == NULL) {
        return -1;
    }
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    if (write(1, str, length) == -1) {
        return -1;
    }
    if (write(1, "\n", 1) == -1) {
        return -1;
    }
    return 0;
}
