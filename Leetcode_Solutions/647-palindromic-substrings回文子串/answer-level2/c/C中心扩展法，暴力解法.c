### 解题思路
每次从中间扩展，需要区分偶数长度和奇数长度的情形。

### 代码

```c
/* 统计回文串数目 */
void helper(char *s, int i, int j, int *res) {
    while (i >= 0 && j < strlen(s) && s[i] == s[j]) {
        i--;
        j++;
        ++(*res);
    }
}

int countSubstrings(char * s){
    int len = strlen(s);
    int res = 0;
    int i = 0;
    if (len == 0) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        /* 奇数回文串 */
        helper(s, i, i, &res);
        /* 偶数回文串 */
        helper(s, i, i + 1, &res);
    }
    return res;
}
```