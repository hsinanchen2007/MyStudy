
C 字符串一定要多一个单元存放‘\0’,不加会溢出,坑了好久...
```


char* reverseLeftWords(char* s, int n){
    int i = 0;
    if(s[0]=='\0'|| n<=0) return s;
    i = strlen(s); //统计s长度

    char *s1 =malloc(sizeof(char)*(i+1));
    int j;
    for(j=0;j<i-n;j++)
    {
        s1[j]=s[n+j];
    }
    
    for(int k=0;k<n;k++)
    {
        s1[i-n+k]=s[k];
    }
    s1[i]='\0';
    return s1;
}
```
