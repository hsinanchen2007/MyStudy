### 解题思路
暴力实现，时间复杂度为O(strlen(haystack)*strlen(needle))。
一出现平方复杂度，很明显这方法太愚蠢！

### 代码

```c
int strStr(char * haystack, char * needle){
    if(strlen(needle) == 0)
        return 0;
    if(strlen(needle) > strlen(haystack))
        return -1;

    int i = 0,cnt = 0;
    while(i <= (strlen(haystack)-strlen(needle)))
    {
        for(int j = i; j <= (i+strlen(needle)-1); j++)
        {
            if(haystack[j] == needle[cnt])
            {
                if(++cnt >= strlen(needle))
                    return i;
            }
            else
            {
                cnt = 0;
                break;
            }
        }
        i++;
    }
    return -1;
}
```