```c
char findTheDifference(char * s, char * t){
    short len=0,i,j,tmp;
    while(s[len]!=0)
        len++;
    if(len==0) return t[0];
    char s_[len];
    for(i=0;i<len;i++)
        s_[i]=s[i];
    char t_[len+1];
    for(i=0;i<len+1;i++)
        t_[i]=t[i];
    for(i=0;i<len;i++)
        for(j=i+1;j<len;j++)
            if(s_[j]<s_[i]){
                tmp=s_[j];
                s_[j]=s_[i];
                s_[i]=tmp;
            }
    for(i=0;i<len+1;i++)
        for(j=i+1;j<len+1;j++)
            if(t_[j]<t_[i]){
                tmp=t_[j];
                t_[j]=t_[i];
                t_[i]=tmp;
            } 
    for(i=0;i<len;i++)
        if(s_[i]!=t_[i])
            return t_[i];
    return t_[len];
}
```