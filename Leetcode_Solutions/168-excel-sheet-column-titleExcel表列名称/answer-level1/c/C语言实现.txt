先计算字母的个数，然后从后向前输出A-Z
```C []
char * convertToTitle(int n){
    int len = 0, tmp = n;
    while (tmp){
        len++;
        tmp = (tmp - 1) / 26;
    }
    char *res = (char*)malloc(len + 1);
    tmp = n;
    res[len] = 0;
    while (len--){
        res[len] = (tmp - 1) % 26 + 'A';
        tmp = (tmp - 1) / 26;
    }
    return res;
}
```