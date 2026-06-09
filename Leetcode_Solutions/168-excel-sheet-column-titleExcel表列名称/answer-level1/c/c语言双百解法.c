偷鸡摸狗偷偷设定他不超过32的长度啦~毕竟应该int类型没那么大的数据

```
char * convertToTitle(int n){
    int tmp=n,len=31;
    char *ch=(char*)malloc(sizeof(char)*(32));
    *(ch+len)='\0';
    while(n>0){
        tmp=(n-1)%26;
        ch[--len]='A'+tmp;
        n=(n-1)/26;
    }
    return ch+len;
}
```
