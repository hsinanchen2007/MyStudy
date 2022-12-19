### 解题思路
此处撰写解题思路

### 代码

```c
char* compressString(char* S){
    int len=strlen(S);
    char *res=(char*)malloc(sizeof(char)*len*2);
    int res_len=0, count=1, j=1;
    char str[25]={0};
    if(len==1)        return S;         //特殊情况
    for(int i=0, j=1;i<len;i++,j++)
    {
        if(S[j]==S[j-1])
            count++;
        else
        {
            res[res_len++]=S[j-1];
            sprintf(str,"%d",count);   //整数转化为字符串 sprintf
            count=1;                //重新赋值
            strcpy(res+res_len,str);
            res_len+=strlen(str);
            memset(str,0,25);
        }
    }
    if(res_len<len)            return res;
    else                        return S;

}

```