```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compressString(char* S)
{
    int len= strlen(S);

    if (len <= 2) {
        return S;
    }

    char *res = malloc(sizeof(char) * (len + 10));
    memset(res, 0, sizeof(char) * (len + 10));

    res[0] = S[0];
    int count = 1;
    int pos = 1;
    for (int i = 1; i <= len; i++) {
        if (S[i] == S[i - 1]) {
            count++;
        } else {
            int tmp = sprintf(res + pos, "%d", count);
            pos += tmp;
            if (S[i] == 0) {
                res[pos] = 0;
            } else {
                res[pos++] = S[i];
                count = 1;
            }

            if (pos >= len) {
                free(res);
                res = NULL;
                break;
            }
        }
    }

    if (res == NULL) {
        res = S;
    }

    return res;
}

```
