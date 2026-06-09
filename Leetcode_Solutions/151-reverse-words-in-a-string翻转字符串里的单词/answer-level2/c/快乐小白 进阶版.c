### 解题思路
垃圾拙码

### 代码

```c
char * reverseWords(char * s){
    int len=strlen(s);
    if(len==0)
    return s;
    for(int i=0;i<len;i++)
    {
        if(s[i]!=' ')
        break;
        if(i==len-1)
        return "";
    }
    char a;
    for(int i=0;i<len/2;i++)
    {
        a=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=a;
    }
    int k=len-1;
    while(s[k]==' ')
    {
        k--;
    }
    len=k+1;
    k=0;
    while(s[k]==' ')
    {
        k++;
    }
    for(int i=k;i<len;i++)
    {
        s[i-k]=s[i];
    }
    len=len-k;
    s[len]='\0';
    k=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]==' '||i==len-1)
        {
            if(i!=len-1)
            i--;
            for(int j=0;j<(i+1-k)/2;j++)
            {
                a=s[k+j];
                s[k+j]=s[i-j];
                s[i-j]=a;
            }
            if(i==len-1)
            {
                break;
            }
            i=i+2;
            int jilu=i;
            while(s[i]==' ')
            {
                i++;
            }
            if(i!=jilu)
            {
                for(int j=i;j<len;j++)
                {
                    s[jilu+(j-i)]=s[j];
                }
                len=len-i+jilu;
                i=jilu;
            }
            k=i;
        }
    }
    s[len]='\0';
    return s;
}
```