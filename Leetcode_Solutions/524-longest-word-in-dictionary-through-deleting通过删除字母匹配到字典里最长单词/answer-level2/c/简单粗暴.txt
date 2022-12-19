### 解题思路
快乐小白  注意 不是字典序号的大小 相同长度字典顺序最小是 按asc表字母对于的值的大小

### 代码

```c
char * findLongestWord(char * s, char ** d, int dSize){
    int j,k,jilu=-1;
    int len,len1=strlen(s),len2=0;
    for(int i=0;i<dSize;i++)
    {
        len=strlen(d[i]);
        if(len<len2)
        continue;
        j=0;k=0;
        while(j!=len&&k!=len1)
        {
            if(d[i][j]==s[k])
            { 
                if((j==len-1&&jilu==-1)||(j==len-1&&len2<len))
                {
                    jilu=i;
                    len2=len;
                    break;
                }
                if(jilu!=-1&&j==len-1&&len==len2)
                {
                    for(int z=0;z<len;z++)
                    {
                        if(d[i][z]==d[jilu][z])
                        continue;
                        if(d[i][z]<d[jilu][z])
                        jilu=i;
                        else
                        break;
                    }
                }
                j++;
            }
            k++;
        }
    }
    if(jilu==-1)
    return "";
    return d[jilu];
}
```