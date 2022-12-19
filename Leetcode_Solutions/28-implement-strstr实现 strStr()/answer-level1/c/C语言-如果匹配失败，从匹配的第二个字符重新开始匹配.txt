```
int strStr(char * haystack, char * needle)
{
    if(haystack== NULL||needle== NULL||strlen(haystack)<strlen(needle))      return -1;
    if(strlen(needle)==0)
    return 0;
    int temp;
    for(int i=0,j=0;i<strlen(haystack);i++)
    {
        if(haystack[i] == needle[j])
        {
            if(j==0)temp = i;
            //printf("%d,%d\n",i,j);
            if(strlen(needle) == j+1)return i-j;
            j++;
        }
        else
        {
            //printf("%d,%d\n",i,j);
            //如果匹配失败，从匹配的第二个字符重新开始匹配
            if(j!=0)
            {
                j=0;
                i = temp;
            }
        }
    }
    return -1;
}
```
