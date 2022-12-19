### 解题思路
此处撰写解题思路

### 代码

```c

char g_out[10000] = {};
// num:[];0 no [];-1,end
int Split(char *s, char *out, int *numLen)
{
    int ret = 0;
    int i;
    const int len = strlen(s);
    if (!isdigit(s[0])) {
        for (i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                break;
            }
        }
        //printf("s=%s i=%d\n", s, i);
        strncpy(out, s, i);
        return 0;
    }

    // is num
    ret =  atoi(&s[0]);
    int begin = 0;
    int end = 0;
    int cnt = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == '[') {
            if (cnt == 0) {
                begin = i + 1;
            }
            cnt++;
        } else if (s[i] == ']') {
            cnt--;
            if (cnt == 0) {
                end = i;
                break;
            }
        }
    }
    *numLen = begin - 1 + 2; // 2 [ ]
    //printf("begin=%d s=%s end %d\n", begin, s, end);
    strncpy(out, (char *)(s + begin), end - begin);
    return ret;
}

void Dfs(int num, char *s, char *out)
{
    //printf("1.1 num %d s=%s\n", num, s);
    char t[1000] = {};
    for (int j = 0; j < num; j++) {
        int k = 0;
        int numLen = 0;
        //printf("1.2 num %d s=%s\n", num, s);
        for (int i = 0; i < strlen(s); i += k) {
            //printf("1.3 num %d s=%s\n", num, s);
            memset(t, 0, sizeof(t));
            //printf("1.4 num %d s=%s\n", num, s);
            //printf("2. s=%s s[i] %c, i %d\n", s, s[i], i);
            int n = Split(&s[i], t, &numLen);
            //printf("n=%d s=%s t=%s, %d\n", n, &s[i], t, numLen);
            if (n == 0) {
                strcat(out, t);   
                //printf("t=%s\n", t);
                k = strlen(t);
            } else {
                Dfs(n, t, out);
                k = strlen(t) + numLen;
            }
        }
    }
}

char * decodeString(char *s)
{
    memset(g_out, 0, sizeof(g_out));
    char t[1000] = {};

    int k = 0;
    int numLen = 0;
    for (int i = 0; i < strlen(s); i += k) {
        memset(t, 0, sizeof(t));
        //printf("t=%s, %d\n", t, sizeof(t));
        int n = Split(&s[i], t, &numLen);
        //printf("n=%d s=%s t=%s, %d\n", n, &s[i], t, numLen);
        if (n == 0) {
            strcat(g_out, t);   
            k = strlen(t);        
        } else {
            Dfs(n, t, g_out);
            k = strlen(t) + numLen;
        }
    }
    return g_out;
}
















```