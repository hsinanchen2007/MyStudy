```

char * decodeAtIndex(char * S, int K){
    char* res = (char*)calloc(3, sizeof(char));
    int len = strlen(S);
    long count = 0;

    /* 先计算字串展开后的总长度 */
    for (int i = 0; i < len; i++) {
        if (isalpha(S[i])) {
            count++;
            continue;
        }
        if (isdigit(S[i])) {
            count *= (S[i] - '0');
            continue;
        }
    }
    if (K > count) {
        return NULL;
    }
    /* 从后往前裁剪字串 */
    long sNo = count;
    for (long j = len - 1; j >= 0; j--) {
        memset(res, 0, 3 * sizeof(char));
        if (K == 0 && isalpha(S[j])) {
            res[0] = S[j];
            res[1] = '\0';
            return  res;
        }
        if (isdigit(S[j])) {
            int num = (int)(S[j] - '0');
            sNo = sNo/num;  /* 因为计算的时候，是前面所有字串乘以数字，因此遇到数字，除掉后就是剩下的字串数，而且不会出现小数 */
            K %= sNo;
        } else if (K == sNo) {
            res[0] = S[j];
            res[1] = '\0';
            return res;
        } else {
            sNo--;
        }
    }
    return res;
}
```
