### 解题思路
1、注意接收数组需要多一位空间；
2、使用求余实现移位；

### 代码

```c
char* reverseLeftWords(char* s, int n){
    
    int len=strlen(s);
    char *str=malloc(sizeof(char)*(len+1));
    int i=0;
    for(i=0;i<len;i++)
    {
       *(str+i)=s[(n+i)%len];
    }
    *(str+i)='\0';
    return str;

}
```