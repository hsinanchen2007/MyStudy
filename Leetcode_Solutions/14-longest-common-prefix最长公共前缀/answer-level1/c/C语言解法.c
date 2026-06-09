### 解题思路
直接比较算出相同字母个数，在第一个中插入‘\0’直接返回即可

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize)
{
    int i,j;
    if(strsSize<1)
    return "";
    for(i=0;strs[0][i]!='\0';i++)
    {
        //k++;
        for(j=1;j<strsSize;j++)
        {
            if(strs[j][i]!=strs[0][i])
            {strs[0][i]='\0';
            return strs[0];
            }
        }
        
    }
    return strs[0];
}
```