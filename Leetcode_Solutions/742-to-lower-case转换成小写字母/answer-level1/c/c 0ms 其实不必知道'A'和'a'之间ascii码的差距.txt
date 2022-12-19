

### 代码

```c
char * toLowerCase(char * str){
    int d = 'a' - 'A';
    //if ch=='A' , ch += d ,ch='a'
    int i=0;
    for(i=0;str[i]!='\0';i++){
        if(str[i]>='A'&&str[i]<='Z')str[i]+=d;
    }
    return str;
}
```