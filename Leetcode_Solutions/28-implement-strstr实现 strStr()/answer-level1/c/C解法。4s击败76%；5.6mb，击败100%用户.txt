### 解题思路
此处撰写解题思路
看了大家打代码，要不投机取巧，要不想的太复杂。一遍循环，行就输出，不行就退到误以为找到的下一个。
### 代码

```c
int strStr(char * haystack, char * needle){
    int si = 0;
    int di = 0;
    int tmp = 0;

    if(needle[0] == 0)
    {
        return 0;
    };

    for(si=0;haystack[si] != 0;si++)
    {
        di = 0;
        if(haystack[si] == needle[di])
        {
            tmp = si;
            for(di=0;(needle[di] != 0) && (haystack[si] != 0);di++,si++)
            {
                if(haystack[si] != needle[di])
                {
                    break;
                };
            };

            if(needle[di] == 0)
            {
                return si-di;
            };

            if(haystack[si] == 0)
            {
                break;
            };

            si = tmp;
        }
    };

    return -1;
}
```