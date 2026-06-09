分为两种情况向两边搜索。

注意结果赋值的时候，如果结果左右节点分别为 l, r, 那么需要用如下方式分配答案

```C
len = res_r - res_l + 1;
char *res = (char *)malloc(sizeof(char) * (len + 1));
strncpy(res, s + res_l, len);
res[len] = '\0'; 
```

题解
```C
char * longestPalindrome(char * s){
    int l, r;
    int len = strlen(s);
    int start = 0;
    int res_l = 0, res_r = 0;
    while(start < len) {
        l = start;
        r = start;
        while(r < len && l >= 0 && s[l] == s[r]) {
            l--;
            r++;
        }
        r--;
        l++;
        if ((res_r - res_l) < (r - l)) {
            res_r = r;
            res_l = l;
        }
        start++;
    }
    start = 0;
    while(start < len) {
        l = start;
        r = start + 1;
        while(r < len && l >= 0 && s[l] == s[r]) {
            l--;
            r++;
        }
        l++;
        r--;
        if ((res_r - res_l) < (r - l)) {
            res_r = r;
            res_l = l;
        }
        start++;
    }
    len = res_r - res_l + 1;
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    strncpy(res, s + res_l, len);
    res[len] = '\0';
    return res;
}
```
