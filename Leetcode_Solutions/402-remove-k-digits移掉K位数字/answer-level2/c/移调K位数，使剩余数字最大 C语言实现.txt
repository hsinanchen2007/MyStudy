核心思想： 从左往右，如果后一位比当前位小，移除当前位。 否则，移除最后一位。
最后去零就好了。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *CutPreZero(char *in)
{
    char *ret = in;
    while (*ret && *ret == '0') {
        ret++;
    }
    if (*ret == 0) {
        return "0";
    }
    return ret;
}

static void RemoveAt(char *num, int index, int *len)
{
    for (; index < *len; index++) {
        num[index] = num[index + 1];
    }
    num[--*len] = 0;
}

static void RemoveOneNum(char *num, int *len)
{
    for (int i = 0; i < *len - 1; i++) {
        // remove bigger one;
        if (num[i] > num[i + 1]) {
            RemoveAt(num, i, len);
            return;
        }
    }
    // remove last one.
    num[--*len] = 0;
}

char *removeKdigits(char *num, int k)
{
    int len = strlen(num);
    // delete all.
    if (k == len) {
        return "0";
    }
    // delete nothing.
    if (k == 0) {
        return CutPreZero(num);
    }
    // remove str[i] when str[i] > str[i+1]. or else remove last one.
    for (; k != 0; k--) {
        RemoveOneNum(num, &len);
    }
    // remove prefix '0'
    return CutPreZero(num);
}


```
