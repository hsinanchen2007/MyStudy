### 解题思路
此处撰写解题思路

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)return "";
    int len=strlen(strs[0]);
    char *p=strs[0];
    int m=0;
    for(int i=0;i<len;i++)
    {
        int flag=1;
        for(int j=1;j<strsSize;j++)
        {
            if(strs[0][i]!=strs[j][i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            m++;
        }
        else{
            p[m]='\0';
            return p;
        }
    }
    p[m]='\0';
    return p;
}
```