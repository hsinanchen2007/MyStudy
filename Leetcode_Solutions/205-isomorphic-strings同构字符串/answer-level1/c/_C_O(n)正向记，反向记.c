### 解题思路
来回映射即可解，避免字符重复映射。
![123.PNG](https://pic.leetcode-cn.com/625eeab45beb99d610193cecc892fbbd29bfa13d8a988b56448eb63ce8d1f484-123.PNG)


### 代码

```c
#define MAXS 512
bool isIsomorphic(char * s, char * t) {
    if (s == NULL || t == NULL) {
        return true;
    }
    int len = strlen(s);
    char replaceChar[MAXS];
    char reverseChar[MAXS];
    memset(replaceChar, '\0', sizeof(char) * MAXS);
    memset(reverseChar, '\0', sizeof(char) * MAXS);
    for (int i = 0; i < len; i++) {
        if (replaceChar[s[i]] == '\0') {
            replaceChar[s[i]] = t[i];
        } else {
            if (replaceChar[s[i]] != t[i]) {
                return false;
            }
        }
        if (reverseChar[t[i]] == '\0') {
            reverseChar[t[i]] = s[i];
        } else {
            if (reverseChar[t[i]] != s[i]) {
                return false;
            }
        }
    }
    return true;
}
```