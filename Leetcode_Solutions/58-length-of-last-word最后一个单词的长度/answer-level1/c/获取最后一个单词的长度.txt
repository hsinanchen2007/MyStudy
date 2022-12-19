### 解题思路
本题字符串有两种类型：
（1）字符串最后的字符不是空格

（2）字符串最后的字符是空格

思路：
1 从后向前遍历字符串
    1.1 如果字符串最后是空格，则计算出有多少个空格
    1.2 如果字符串最后不是空格，则等于零

2 从字符串最后一个不是空格的字符进行遍历，直到遇到空格

3 返回最后一个单词的长度

### 代码

```c
int lengthOfLastWord(char * s)
{
    int len = strlen(s);
    int i,j,n=0;
    int f = 0;
    if(len == 0)
    {
        return 0;
    }

    for(i = len -1; i >0;i--)
    {
        if(s[i] != ' ')
        {
            break;
        }
        else
        {
            f++;
        }
    }

    for(i = len -f - 1; i >= 0; i--)
    {
        if(s[i] == ' ')
        {
            break;
        }
    }
    n = len - f - i - 1;

    return n;
}
```