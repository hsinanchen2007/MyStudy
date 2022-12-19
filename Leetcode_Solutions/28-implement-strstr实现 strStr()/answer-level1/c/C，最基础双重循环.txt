### 解题思路
C中最基础的循环，通过一重循环实现待查找字符串与原文本的一一对应，再通过一重循环找到字符串的位置，不过执行用时很长

### 代码

```c
int strStr(char * haystack, char * needle)
{
    if (strlen(needle)==0)
      return 0;

    int n1=strlen(haystack);
    int n2=strlen(needle);
    int i,j;
    if(n2 > n1)
      return -1;
    for(i=0; i<n1; i++)
    {
       for(j=0; j<n2; j++)
           if(haystack[i+j]!=needle[j])
           break;
       if(j==n2)//记录循环的位置
        return i;
    }
    return -1;
}
```