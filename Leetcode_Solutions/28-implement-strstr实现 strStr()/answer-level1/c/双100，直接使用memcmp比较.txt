### 解题思路
此处撰写解题思路

### 代码

```c
int strStr(char * haystack, char * needle){
    int i;
    int n_l = strlen(needle);
    int h_l = strlen(haystack);
    
    if(NULL == haystack || NULL == needle || 0 == n_l)
        return 0;

    for(i = 0; (i + n_l) <= h_l ; i++)
    {
        if(0 == memcmp(&haystack[i], needle, n_l))
        {
            return i;
        }
    }

    return -1;
}
```