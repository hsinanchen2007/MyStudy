char* reverseLeftWords(char* s, int n){
    int k,i,j,len=0;
    for(i=0;s[i]!='\0';i++)
    {
        len=len+1;
    }
    for(i=1;i<=n;i++)
    {
        k=s[0];
        for(j=0;j<len-1;j++)
        {
            s[j]=s[j+1];
        }
        s[j]=k;
    }
    return s;
}

保留第一个元素 
数组往前移动  
之前保留的第一个元素赋值给最后一个下标
左移几个 循环几次