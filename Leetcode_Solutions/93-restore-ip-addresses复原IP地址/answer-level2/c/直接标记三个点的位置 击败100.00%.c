
i：代表第一个点可到达的最后一个位置
j：代表第二个点可到达的最后一个位置
k：代表第三个点可到达的最后一个位置
## 代码
```
int getnum(char *s, int l, int r) {
    if (l < r && s[l] == '0') return -1;
    int x = 0;
    while (l <= r && x <= 255) {
        x = x * 10 + (s[l] - '0');
        l++;
    }
    return x;
}
char ** restoreIpAddresses(char * s, int* returnSize){
    char **res = (char **)malloc(sizeof(char *) * 200);
    *returnSize = 0;
    int num, len = strlen(s);
    for (int i = 0; i < 3; i++) {
        num = getnum(s, 0, i);
        if (num < 0 || num > 255 || i == len - 3) break;
        for (int j = i + 1; j <= i + 3; j++) {
            num = getnum(s, i + 1, j);
            if (num < 0 || num > 255 || j == len - 2) break;
            for (int k = j + 1; k <= j + 3; k++) {
                num = getnum(s, j + 1, k);
                if (num < 0 || num > 255 || k == len - 1) break;
                num = getnum(s, k + 1, len - 1);
                if (num >= 0 && num <= 255) {
                    res[*returnSize] = (char *)malloc(sizeof(char) * (len + 4));
                    int col = 0;
                    for (int ind = 0; ind < len; ind++) {
                        res[*returnSize][col++] = s[ind];
                        if (ind == i || ind == j || ind == k) res[*returnSize][col++] = '.';
                    }
                    res[*returnSize][col] = '\0';
                    (*returnSize)++;
                }
            }
        }
    }
    return res;
}
```

