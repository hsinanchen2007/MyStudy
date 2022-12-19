第一个数组依次和后续的数组进行查找最长公共前缀，然后返回前缀作为新的数组依次和后续的数组查找
最长公共前缀。
这里做了两个改进使得时间快了不少，第一个是返回数组要给末尾填上'\0'
第二个是判断收到的新数组是否为'\0'
```
char *findMin(char *str1,char *str2)
{
    int length=0;
    char *p1=str1,*p2=str2;
    while(*p1==*p2&&*p2!='\0')//找出最小相同子串的长度
    {
        length++;
        p1++;p2++;
    }
    char *str3=(char *)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;i++)
        str3[i]=str1[i];
    str3[length]='\0';
    return str3;   
}
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)
    return "";
    if(strsSize==1)
    return *strs;
    int i;
    char *p=*strs;
    for(i=1;i<strsSize;i++)
    {
        if(*p=='\0')
            return "";
        else
            p=findMin(p,*(strs+i));
    }
    return p;
}
```
