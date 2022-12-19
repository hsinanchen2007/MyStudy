### 解题思路
这大概是很清晰的思路了吧。
把第一个字符串作为参照物。
后面的字符串每次从位置0开始与第一个字符串的位置0相比，不相等退出所有循环，对比结束。若相等则继续。

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize) {
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    int j = 0, i;
    for(; strs[0][j] != '\0'; j++) {
        for(i = 1; i < strsSize && strs[i][j] != '\0'; i++) {
            if (strs[i][j] != strs[0][j]) break;
        }
        if (i < strsSize)
        {
            strs[0][j] = '\0';
            break;
        }
    }
    return strs[0];

}
```

