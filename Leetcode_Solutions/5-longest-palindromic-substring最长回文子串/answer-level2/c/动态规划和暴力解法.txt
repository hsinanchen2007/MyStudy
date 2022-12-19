### 解题思路
此处撰写解题思路

### 代码

#if 0 //暴力解法
char * longestPalindrome(char * s){
    int lens;
    int i, j, k, start, end;
    char *buf;

    lens = strlen(s);
    buf = malloc(lens + 1);
    memset(buf, 0, lens + 1);

    if (!s) {
        return NULL;
    }

    if (strlen(s) == 0) {
        return buf;
    }

    for (k = lens; k >= 1; k--) {
        for (i = 0, j = 0; j < lens; i++) {
            j = i + k - 1;
            for (start = i, end = j; start < end; start++, end--) {
                if (s[start] != s[end]) {
                    break;
                }
            }

            if (start >= end) {
                memcpy(buf, s + i, k);
                return buf;
            }
        }
    }

    return NULL;
}
#endif

//动态规划
char * longestPalindrome(char * s){
    int lens, max = 0;
    int i, j, k, start, end;
    char *buf;
    char pd[1000][1000] = {0};
    unsigned short pos[2] = {0};

    if (!s) {
        return NULL;
    }


    lens = strlen(s);
    buf = malloc(lens + 1);
    memset(buf, 0, lens + 1);

    if (strlen(s) == 0) {
        return buf;
    }

    for (i = lens - 1; i >= 0; i--) {
        for (j = i; j < lens && j >= 0; j++) {
            if (i == j) {
                pd[i][j] = 1;
            } else if (j - i == 1) {
                if (s[i] == s[j]) {
                    pd[i][j] = 1;
                    if (j - i > max) {
                        max = j - i;
                        pos[0] = i;
                        pos[1] = j;
                    }                   
                }
            } else if (pd[i + 1][j - 1] && s[i] == s[j]) {
                pd[i][j] = 1;
                if (j - i > max) {
                    max = j - i;
                    pos[0] = i;
                    pos[1] = j;
                }
            }
        }
    }

    strncpy(buf, s + pos[0], pos[1] - pos[0] + 1);

    return buf;
}

```