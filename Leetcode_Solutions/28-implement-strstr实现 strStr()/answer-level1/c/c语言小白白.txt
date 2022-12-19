### 解题思路

暴力解法，数据量大了就用不了了。
### 代码

```c


int strStr(char * haystack, char * needle){
    int size1 = strlen(haystack);
    int size2 = strlen(needle);
    if(!size2)
        return 0;
    int p,q;
    for(p=0;p<=size1-size2;p++)
    {
        for(q=0;q<size2;q++)
        {
            if(haystack[p+q]!=needle[q])
            break;
        }
        if(q==size2)
            return p;
    }
    return -1;
}


```