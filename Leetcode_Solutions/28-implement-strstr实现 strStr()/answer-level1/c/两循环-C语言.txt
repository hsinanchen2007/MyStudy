### 解题思路
两个for循环查找

### 代码

```c
int strStr(char * haystack, char * needle){
    if(needle[0]=='\0')
        return 0;
    if(haystack[0]=='\0')
        return -1;
    int i=0;
    for(i;haystack[i] != '\0';i++)
    {
        int j=0;
        for(j;needle[j] != '\0';j++)
        {
            if(haystack[i+j] == '\0')
                return -1;
            if(haystack[i+j] != needle[j])
                break;
        }
        if(j==strlen(needle))
            return i;
    }
    return -1;
}
```