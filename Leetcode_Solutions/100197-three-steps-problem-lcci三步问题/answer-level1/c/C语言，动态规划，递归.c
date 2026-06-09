### 解题思路
此处撰写解题思路

### 代码

```c
int waysToStep(int n){
    int i;
    int ret;
    long long *opt = (long long *)malloc(sizeof(long long) * (n + 4));
    opt[0] = 1;
    opt[1] = 1;
    opt[2] = 2;
    opt[3] = 4;
    for (i = 4; i <= n; i++) {
        opt[i] = opt[i - 1] + opt[i - 2] + opt[i - 3];
        opt[i] = opt[i] % 1000000007;
    }
    ret = opt[n];
    free(opt);
    opt = NULL;
    return ret;
}
```