```
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0) return "";//没字符串时
    else if(strsSize == 1) return *strs;///就一字符串时
    int i=0,j=0;//变量
    char *a=(char*)malloc(128);//动态创建 
    char *b=a;//跳板
    memset(a,0,128);//不懂  抄的
    while(1)
    {
        if(i<strsSize-1)//循环字符串数-1的次数
        {
            if(strs[i][j]==strs[i+1][j] && strs[i][j]!='\0') //判断是否相等且不为空
            {
                i++;//变量自增
            }
            else 
            {
                return b;//不相等直接返回
            }
        }
        else
        {
            *a++ = strs[i][j];//存储公共前缀
            i=0;//清零
            j++;//j自增
        }
    }
    return 0;//非要我加上去
}
```
memset(a,0,128);死在这一步