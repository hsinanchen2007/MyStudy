### 解题思路
1.利用C库函数strtok()分割字符串
2.将每个单词逆置存放在结果字符串中
3.最后再逆置整个结果字符串

### 代码

```c


char* reverseWords(char* s){
    int len=strlen(s);
    char *res=(char*)malloc(sizeof(char)*(len+1));
    char *ch=" ";   //分隔符为' '(空格))
    char *token;
    int i=0,k=0,j=0;
    token=strtok(s,ch);
    if(!token) return "";   //排除""和" "字符串
    while(token){
        int temp=strlen(token)-1;
            for(;temp>=0;temp--){
                res[k++]=token[temp];   将the->eht放入结果字符串
            }
            res[k++]=' ';
        token=strtok(NULL,ch);
    }
    res[--k]='\0';
    for(i=0,j=k-1;i<j;i++,j--){     //将整个结果字符串逆置
        char t=res[i];
        res[i]=res[j];
        res[j]=t;
    }
    return res;
}


```
写的有点繁琐了