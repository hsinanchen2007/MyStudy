### 解题思路
此处撰写解题思路

### 代码

```c

bool check(char S)
{
    if (S == 'a' || S == 'e' || S == 'i' || S == 'o' || S == 'u' || \
        S == 'A' || S == 'E' || S == 'I' || S == 'O' || S == 'U') {
        return true;
    }
    return false;
}

char * toGoatLatin(char * S){
    if (S == NULL) return S;
    int len = strlen(S), idx = 0, cnt = 1;
    char *res = (char *) malloc(sizeof(char) * (25000));
    for (int i = 0, j = 0; i < strlen(S); i++) {
        while (S[j] != ' ' && j < len) j++;
        if (check(S[i])) {
            for (int k = 0; k < j - i; k++) {
                res[idx++] = S[i + k];
            }
            res[idx++] = 'm';
            res[idx++] = 'a';
        } else {
            for (int k = 1; k < j - i; k++) {
                res[idx++] = S[i + k];
            }
            res[idx++] = S[i];
            res[idx++] = 'm';
            res[idx++] = 'a';
        }
        for (int u = 0; u < cnt; u++) res[idx++] = 'a';
        res[idx++] = ' ';
        i = j;
        cnt++;
        j++;
    }
    res[--idx] = '\0';
    return res;
}
```