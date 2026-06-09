C语言实现
```C []
char * licenseKeyFormatting(char * S, int K){
    int len = strlen(S);
    char *D = (char*)malloc(2 * len);
    memset(D, 0, 2 * len);
    int i = len - 1, j = 0;
    while (i >= 0){
        if (S[i] != '-'){
            D[j++] =  (S[i] < 'a') ? S[i] : S[i] - 0x20;
            if (j % (K + 1) == K) D[j++] = '-';
        }
        --i;
    }
    if (0 == j) return "";

    if (D[j - 1] == '-') D[--j] = 0;
    for (i = 0; i < j / 2; ++i) {
        char tmp = D[i];
        D[i] = D[j - 1 - i];
        D[j - 1 - i] =  tmp;
    }
    return D;
}
```
