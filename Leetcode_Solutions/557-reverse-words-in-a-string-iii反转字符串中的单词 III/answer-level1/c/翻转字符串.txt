#include <stlib.h>
#include <string.h>

#define MAX_LEN 1024

int stringRevert(*strings) {
    char temp;
    int _start = 0;
    int len = strnlen_s(strings, MAX_LEN);

    if (!len)
        return -1;
    while (_start < len - 1) {
        temp = strings[_start];
        strings[_start] = strings[len];
        strings[len] = temp;
        _start++;
        len--;
    }
    return 0;
}