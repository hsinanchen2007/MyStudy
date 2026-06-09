### 解题思路
1. 注意会出现strsSize == 0情况，返回"\0"
2. 对每一列字符进行比较，遍历到"\0"或不相同字符是结束，将此字节置"\0"，返回头指针

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    int i, j = 0;

    if (strsSize == 0) return "\0";

    while (strs[0][j] != '\0') 
    {
        for (i = 0; i < strsSize; i++)
        {
            if (strs[i][j] == '\0' || strs[i][j] != strs[0][j]) 
            {
                strs[0][j] = '\0';
                return strs[0];
            }
        }
        j++;
    }
    return strs[0];
}
```