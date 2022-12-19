### 解题思路
暴力解决，字串长度从1到strlen(s),判断相同则返回true，否则false。

### 代码

```c
bool repeatedSubstringPattern(char * s){

    int i, j;
    int strlength = strlen(s);
    for (i = 1; i < strlen(s); i++) {
        int len = i;
        if (strlength % len != 0) {
            continue;
        }
        char tmp[10000] = {0};
        strncpy(tmp, s, len);
        for(j = 0; j < strlength; j += len) {
            if (strncmp(s + j, tmp, len) != 0) {
                break;
            }
        }
        if (j == strlength) {
            return true;
        }
    }
    return false;
}
```