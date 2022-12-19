一重循环
```
char g_str[100000][1000];
int g_num;
char ss[100000];
void reverseWords(char* s, int sSize)
{
    int i, len, j, k;
    g_num = 0;
    j = 0;
    for (i = 0; i <= sSize; i++) {
        if ((i == sSize) || (s[i] == ' ')) {
            g_str[g_num][j] = '\0';
            g_num++;
            j = 0;
        } else {
            g_str[g_num][j] = s[i];
            j++;    
        }
    }
    
    k = 0;
    for (i = g_num - 1; i >= 0; i--) {
        len = strlen(g_str[i]);
        for (j = 0; j < len; j++) {
            ss[k] = g_str[i][j];
            k++;
        }
        ss[k] = ' ';
        k++;
    }
    for (i = 0; i < sSize; i++) {
        s[i] = ss[i];
    }
}
```
额外O(1)空间
```
char ss[100000];

void reverseWords(char* s, int sSize)
{
    int i, j, startIdx, endIdx, ssIdx;
    endIdx = sSize - 1;
    ssIdx = 0;
    for (i = sSize - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            startIdx = i + 1;
            for (j = startIdx; j <= endIdx; j++) {
                ss[ssIdx] = s[j];
                ssIdx++;
            }
            ss[ssIdx] = ' ';
            ssIdx++;
            endIdx = i - 1;
        }
    }
    for (j = 0; j <= endIdx; j++) {
        ss[ssIdx] = s[j];
        ssIdx++;
    }
    for (i = 0; i < sSize; i++) {
        s[i] = ss[i];
    }
}

```

