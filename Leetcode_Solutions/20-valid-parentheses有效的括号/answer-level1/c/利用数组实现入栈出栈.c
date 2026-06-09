### 解题思路
此处撰写解题思路

### 代码

```c
#include <string.h>
#include <stdio.h>

bool isMachedChar(char i, char j) 
{
    if (i == '[' && j == ']' || 
        i == '(' && j == ')' ||
        i == '{' && j == '}') {
        return true;
    }

    return false;
}

void dealStVsS(char *s, char *st, int len)
{
    int k = 0;
    st[0] = s[0];

    for (int i=1; i < len; i++) {        
        if (isMachedChar(st[k], s[i])) {
            if (k == 0 && i < len) {
                i++;
                st[0] = s[i];
            } else {
                st[k] = '\0';
                k--;
            }

        } else {
            k++;
            st[k] = s[i];
        }
    }
    return;
}

bool isValid(char * s){
    if (s == NULL) {
        return false;
    }

    int len = strlen(s);
    if (len % 2 != 0) {
        return false;
    }

    char *st = malloc(sizeof(char) * len);
    (void)memset(st, '\0', len);

    dealStVsS(s, st, len);
    if (st[0] == '\0') {
        return true;
    } else {
        return false;
    }
}
```