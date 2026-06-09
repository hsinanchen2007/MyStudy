### 解题思路
设置numrows个char  存放每一行的字母

### 代码

```c
char * convert(char * s, int numRows){
    int len=strlen(s);
    if(numRows==1||len==1)
    return s;
    char **b=(char**)malloc(numRows*sizeof(char*));
    for(int i=0;i<numRows;i++)
    {
        b[i]=(char*)calloc(len,sizeof(char));
    }
    int k=1,l=0;
    int a[numRows];
    memset(a,0,sizeof(a));
    for(int i=0;i<len;i++)
    {
        b[l][a[l]++]=s[i];
        l=l+k;
        if(l==numRows-1)
        k=-1;
        if(l==0)
        k=1;
    }
    len=0;
    for(int i=0;i<numRows;i++)
    {
        int j=0;
        while(b[i][j]!='\0')
        {
            s[len++]=b[i][j++];
        }
    }
    return s;
}
```