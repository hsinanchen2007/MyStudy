```
typedef char Element;
int* computePrefix(Element* s, int sSize) {
    int* res = malloc(sizeof(int) * sSize);
    res[0] = 0;
    int k = 0;
    for (int i = 1; i < sSize; i++) {
        while (k > 0 && s[i] != s[k]) k = res[k - 1];
        if (s[i] == s[k]) k++;
        res[i] = k;
    }
    return res;
}
int repeatedStringMatch(char * A, char * B){
    int aLen = strlen(A), bLen = strlen(B);
    int L = bLen / aLen + 2;
    char* C = malloc(sizeof(char) * (aLen * L + 1));
    memset(C, 0, sizeof(char) * (aLen * L + 1));
    for (int i = 0; i < L; i++) {
        sprintf(C, "%s%s", C, A);
    }
    int* arr = computePrefix(B, bLen);
    int i, j = 0, flag = 0;
    int n = aLen * L + 1;
    for (i = 0; i < n; i++) {
        while (j > 0 && B[j] != C[i]) j = arr[j - 1];
        if (B[j] == C[i]) j++;
        if (j == bLen) {
            flag = 1;
            break;
        }
    }
    free(arr);
    free(C);
    if (flag == 0) return -1;
    else {
        return i / aLen + 1;
    }
```

