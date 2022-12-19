### 解题思路
方法一:遍历查找，遇到新单词则重新计数，直到结束

### 代码

```c
//方法一:遍历查找，遇到新单词则重新计数，直到结束
int lengthOfLastWord(char * s){
    int     i       = 0;
    int     iRet    = 0;

    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            i += 1;
        }
        else
        {
            if ((iRet != 0) && (s[i - 1] == ' '))
            {
                iRet = 1;
            }
            else
            {
                iRet += 1;
            }
            i += 1;
        }
    }
    return iRet;
}
```