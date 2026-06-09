抱着会超时的心态试了一下，没想到过了，看来数据不够多
```
char * shortestPalindrome(char * s){
    int len = strlen(s);
    if (len == 0) {
        return "";
    }
    int l = 0;
    int k = len - 1;
    int r = k;
    while (l < r) {
        if (s[l] != s[r]) {
            l = 0;
            r = --k;
        } else {
            l++;
            r--;
        }
    }
    char *res = (char*)malloc((2 * len - k) * sizeof(char));
    memset(res, 0, (2 * len - k) * sizeof(char));
    for (int i = 0; i < len - k - 1; i++) {
        res[i] = s[len - i - 1];
    }
    for (int i = len - k - 1; i < 2 * len - k; i++) {
        res[i] = s[i - (len - k - 1)];
    }
    return res;
}
```
