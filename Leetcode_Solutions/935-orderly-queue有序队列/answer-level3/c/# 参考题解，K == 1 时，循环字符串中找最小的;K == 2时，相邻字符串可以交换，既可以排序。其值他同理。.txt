# 参考题解，K == 1 时，循环字符串中找最小的;K == 2时，相邻字符串可以交换，既可以排序。其值他同理。
```
int cmp(const void *p1, const void *p2)
{
    char a = *(char *)p1;
    char b = *(char *)p2;
    return a > b ? 1 : -1;
}
char * orderlyQueue(char * S, int K){
    int len = strlen(S);
    if (K == 1) {        
        char *res = (char *)malloc((2 * len + 1) * sizeof(char));
        memset(res, 0, (2 * len + 1) * sizeof(char));
        memcpy(res, S, len);
        memcpy(res + len, S, len);
        int index = 0;
        for (int i = 0; i < len;i ++) {
            if (strcmp(res + i, res + index) < 0) {
                index = i;
            }
        }
        res[len + index] = 0;
        return res + index;
    }else {
        qsort(S, len, sizeof(char), cmp);
        return S;
    }
}
```
