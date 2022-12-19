### 解题思路
    首先我发现一个问题：把代码中所有calloc换成malloc,就会出现heap-buffer-overflow的问题。目前正在查资料找原因。
存在最大字串条件:str1+str2==str2+str1    //字符串拼接
若存在，只需找出最大字串的长度，利用str1,str2必为最大字串res的m和n倍来求（即用辗转相除法来求最大公约数），最后在拼接即可。

C语言字符串处理稍有不便,常用字符串函数api:
    int strlen(char *str)
    char* strcpy(char *des,char *src); 字符串复制，返回值也为des
    char* strcat(char *des,char *src);字符拼接
    char* strncpy(char *des,char *src,int length);可选长复制
    以及分配堆空间calloc(int length,int type_size);
### 代码

```c
char * gcdOfStrings(char * str1, char * str2){
    int gcd(int a,int b);                   //声明
    int str1_len=strlen(str1),str2_len=strlen(str2);
    char *p=(char *)calloc((str1_len+str2_len+1),sizeof(char));
    char *q=(char *)calloc((str1_len+str2_len+1),sizeof(char));
    strcpy(p,str1);strcpy(q,str2);          //复制
    strcat(p,str2);strcat(q,str1);         //拼接
    if(strcmp(p,q)!=0)return "";
    //求字串
    int len = str1_len>str2_len?gcd(str1_len,str2_len):gcd(str2_len,str1_len);
    char *res=(char *)calloc(len+1,sizeof(char));
    strncpy(res,str1,len);
    return res;
}
int gcd(int a,int b){                   //递归求最大公约数
    return b==0?a:gcd(b,a%b);
}
```