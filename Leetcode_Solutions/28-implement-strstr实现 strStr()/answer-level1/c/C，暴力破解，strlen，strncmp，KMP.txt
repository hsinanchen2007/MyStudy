### 解题思路
方法一：双指针暴力破解，效率低下
方法二：使用 strlen双指针暴力破解
方法三：使用 strlen 和 strncmp 函数
方法四：KMP算法，不会
### 代码

```c

//方法四：KMP算法，不会

//方法三：使用 strlen 和 strncmp 函数
int strStr(char * haystack, char * needle){
    int     i       = 0;
    int     j       = 0;
    int     iHlen   = strlen(haystack);
    int     iNlen   = strlen(needle);
    int     iRet    = -1;

    if ((NULL == needle) || (needle[0] == '\0'))
    {
        iRet = 0;
        return iRet;
    }

    if ((NULL == haystack) || (haystack[0] == '\0'))
    {
        return iRet;
    }

    for (i = 0; i <= iHlen - iNlen; i++)
    {
        if (haystack[i] == needle[0])
        {
            if (0 == strncmp(&haystack[i], &needle[0], iNlen))
            {
                iRet = i;
                break;
            }
        }
    }

    return iRet;
}

/*
//方法二：使用 strlen双指针暴力破解
int strStr(char * haystack, char * needle){
    int     i       = 0;
    int     j       = 0;
    int     iHlen   = strlen(haystack);
    int     iNlen   = strlen(needle);
    int     iRet    = -1;

    if ((NULL == needle) || (needle[0] == '\0'))
    {
        iRet = 0;
        return iRet;
    }

    if ((NULL == haystack) || (haystack[0] == '\0'))
    {
        return iRet;
    }

    for (i = 0; i <= iHlen - iNlen; i++)
    {
        for (j = 0; j < iNlen; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
        }

        if (j >= iNlen)
        {
            iRet = i;
            break;
        }
    }
    return iRet;
}
*/
/*
//方法一：双指针暴力破解，效率低下
int strStr(char * haystack, char * needle){
    int     i       = 0;
    int     j       = 0;
    int     iRet    = -1;
    int     iFlag   = 1;

    if ((NULL == needle) || (needle[0] == '\0'))
    {
        iRet = 0;
        return iRet;
    }

    if ((NULL == haystack) || (haystack[0] == '\0'))
    {
        return iRet;
    }

    while (haystack[i] != '\0')
    {
        iFlag = 1;
        while ((needle[j] != '\0'))
        {
            if (haystack[i + j] != '\0')
            {
                if (haystack[i + j] != needle[j])
                {
                    iFlag = 0;
                    break;
                }
            }
            else
            {
                iFlag = 0;
                break;
            }
            j += 1;
        }

        if (iFlag == 1)
        {
            iRet = i;
            break;
        }

        i += 1;
        j = 0;
    }
    return iRet;
}
*/
```