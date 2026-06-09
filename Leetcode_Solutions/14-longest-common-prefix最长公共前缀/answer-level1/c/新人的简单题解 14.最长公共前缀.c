### 解题思路
用一个index表示待比较的下标，对于一个index来说，如果发现所有字符串该位置上的字符不全相等或者某个为'\0'，则说明该结束了，此时的index所指位置，就是最长公共前缀的最后字符的后一位置下标，也可理解为最长公共前缀的长度。注意返回的字符串末尾+'\0',如果输入是空，要特殊处理。

这种算法的时间复杂度取决于公共前缀的长度L和字符串的数量N，每个index要检查是否为'\0',以及检查是否全相等，所以是O(L*N)
### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize)
{
    int index=0;
    int flag=0;
    if(strsSize==0) return &("");
    while(1)
    {
        for(int i=0;i<strsSize-1;i++)
        {
            if(strs[i][index]!=strs[i+1][index]) flag=1;
        }
        for(int k=0;k<strsSize;k++) if(strs[k][index]=='\0') flag=1;
        if(flag==0) index++;
        else break;
    }
    //printf("%d",index);
    char* res=malloc((index+1)*sizeof(char));
    for(int i=0;i<index;i++)
    {
        res[i]=strs[0][i];
    }
    res[index]='\0';
    return res;
}
```