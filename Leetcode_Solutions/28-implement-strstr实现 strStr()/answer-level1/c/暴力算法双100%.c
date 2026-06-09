### 解题思路
暴力算法

### 代码

```c
int strStr(char * haystack, char * needle)
{
int haystack_len=strlen(haystack);
int needle_len=strlen(needle);
int i=0;
int j=0;
while(i<haystack_len&&j<needle_len)
{
    if(haystack[i]==needle[j])
    {
        i++;
        j++;
    }
    else
    {
        i=i-j+1;
        j=0;
    }

}
if(j==strlen(needle))

return i-j;
else
return -1;

    

}
```