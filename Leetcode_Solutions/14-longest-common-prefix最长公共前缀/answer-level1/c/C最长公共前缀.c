char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize == 0||strs[0]=='\0')//预防空字符
    return "";
    char *pubwords=(char*)malloc(128);
    memset(pubwords,0,128);
    int flag=0;
    for(int i=0;i<strlen(strs[0])&&(flag==0);i++)//以第一个字符串的字符为标准，判断其他字符串相同列的字符是否相同
    {
        pubwords[i]=strs[0][i];//将第一个字符串的字符逐个赋给公共字符
        for(int j=0;j<strsSize;j++)
        {
            if((strs[j][i])!=pubwords[i])//如果字符串间同列字符不相同，结束循环，去掉最后赋值的一个字符
            {
                pubwords[i]='\0'; 
                flag=1;
            }
        }   
    }
    return pubwords;
}