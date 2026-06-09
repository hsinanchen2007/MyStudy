### 解题思路
此处撰写解题思路

（1）当字符串数组长度为 0 时则公共前缀为空，直接返回；
（2）strs[0]表示入参的第一个字符串数组；
（3）遍历后面的字符串，依次将其与 strs[0] 进行比较，两两找出公共前缀，最终结果即为最长公共前缀
（4）如果查找过程中出现了 strs[0] 为空的情况，则公共前缀不存在直接返回


### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    char *cmp = NULL;
    int i, j, sz;

    if (strsSize <= 0) {
        return "";
    }

    sz = strlen(strs[0]);

    /* i表示行号 */
    for (i = 1; i < strsSize; i++) {
        /* j表示列对比 */
        for (j = 0; j < sz && j < strlen(strs[i]); j++) {
            if (strs[0][j] != strs[i][j]) {
                break;
            }
        }
        if (j == 0) {
            sz = 0;
            break;
        } else {
            sz = j; 
        }
    }

    if (sz == 0) {
        return "";
    } else {
        cmp = (char *)malloc(sizeof(char) * (sz + 1));
        memset(cmp, '\0', sizeof(char) * (sz + 1));
        strncpy(cmp, strs[0], sz);
    }

    return cmp;
}
```