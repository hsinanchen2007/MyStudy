![捕获.PNG](https://pic.leetcode-cn.com/5c7d5efcbdf14b65bb8981a4114e7599e526a550fc1ddfaf5357d174934daa64-%E6%8D%95%E8%8E%B7.PNG)

### 解题思路
遍历字符串，找到空格数，得到最终字符串长度 = 原始长度 + 空格数 * 2；
新字符串和原始字符串依次从结尾开始遍历，依次复制，遇到空格则替换成%20

### 代码

```c
char* replaceSpace(char* s){
    int iLen = 0;
    int iSpaceLen = 0;
    int iNewLen;
    int i,j;
    char sTmp[10000] = {0};
    char *pcRet = sTmp;

    if ((void *)0 == s)
        return (char*)(void *)0;

    while ('\0' != s[i])
    {
        iLen++;
        if (' '== s[i])
        {
            iSpaceLen++;
        }
        i++;
    }
    
    iNewLen = iLen + iSpaceLen * 2;

    for(i = iNewLen, j = iLen; (i >= j && j >= 0);)
    {
        if (' ' == s[j])
        {
            sTmp[i--] = '0';
            sTmp[i--] = '2';
            sTmp[i--] = '%';
        }
        else
        {
            sTmp[i--] = s[j];
        }
        j--;
    }

    return pcRet;
}
```