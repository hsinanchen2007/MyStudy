### 解题思路
选取第一个字符串作为参照，与后面的字符串逐一比较，某个字符不相同时，此时打上字符串结束标志'\0'。
### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(!strsSize)               /* 空字符串，返回"" */
        return "";

    char *s = *strs;            /* 以第一个字符串为参照 */
    for(int i = 1, j; i < strsSize; ++i) {
        for(j = 0; *(s+j) && *(*(strs+i)+j) && *(s+j) == *(*(strs+i)+j); ++j)   /* 寻找不相同字符的位置 */
            ;
        *(s+j) = '\0';          /* 截断字符串 */
    }
    return s;
}

```

如果指针不是很熟练的话，也可以这样
```c
char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(!strsSize)
        return "";

    int len = strlen(strs[0]);
    char *s = malloc(sizeof(char) * (len+1));
    strcpy(s, strs[0]);
    for(int i = 1, j; i < strsSize; ++i){
        for(j = 0; s[j] && strs[i][j] && s[j] == strs[i][j]; ++j)
            ;
        s[j] = '\0';
    }
    return s;
}

```