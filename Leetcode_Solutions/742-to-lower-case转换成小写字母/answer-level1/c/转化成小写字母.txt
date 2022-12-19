### 解题思路
1.常规做法:判断后+32
2.位操作：和' '(空格)进行|(或操作)

### 代码

```c
char * toLowerCase(char * str){
    int i=strlen(str);
    char *res=(char*)malloc(sizeof(char)*(i+1));
    res[i]='\0';
    for(i=0;str[i]!='\0';i++){
        //res[i]=str[i]>='A'&&str[i]<='Z'?str[i]+32:str[i];
        res[i]=str[i]|' ';      //实际上用的较少
    }
    return res;
}
```