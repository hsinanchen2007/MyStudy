### 解题思路
读懂题意，关键就是操作一次尽可能能量最大

### 代码

```c
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int CalNum(int *arr, int size, int p) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        p = p - arr[i];
        if (p >= 0) {
            res++;
        } else {
            break;
        }
    }
    return res;
}

int bagOfTokensScore(int* tokens, int tokensSize, int P){
    if (tokens == NULL || tokensSize <= 0 || P <= 0) {
        return 0;
    }

    qsort(tokens, tokensSize, sizeof(int), cmp);
    if (P < tokens[0]) {
        return 0;
    }
    
    int Max = CalNum(tokens, tokensSize, P);
    int *h = tokens;
    int *t = tokens + tokensSize -1;
    int tmp;

    for (int j = 1; j < tokensSize / 2; j++) {
        P = P - *(h + j - 1) + *(t - j + 1);
        tmp = CalNum(h + j, tokensSize - j * 2, P);
        if (Max < tmp) {
            Max = tmp;
        }
    }

    return Max;
}
```