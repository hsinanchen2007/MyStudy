```
char * lastSubstring(char * s){
    int len = strlen(s);
    int ans = 0;
    for (int i = 1; i < len; i++) {
        if (s[i] <= s[i - 1]) {
            continue;
        }
        if (strcmp(&s[i], &s[ans]) > 0) {
            ans = i;
        }
    }
    return &s[ans];
}
```
![image.png](https://pic.leetcode-cn.com/70f4f5f2616a8e4cdf2777cfaede29ef279f8d2f85a8dba182c43fe94fe1f996-image.png)

