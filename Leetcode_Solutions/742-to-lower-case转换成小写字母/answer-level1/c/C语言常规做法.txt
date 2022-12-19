```c
char * toLowerCase(char * str){
    int length=0,i;
    while(str[length]!=0) length++;
    char s[length+1];
    for(i=0;i<length;i++)
        s[i]=str[i]>='A'&&str[i]<='Z'?str[i]+32:str[i];
    s[length]=0;
    char* string;
    string=s;
    return string;
}
```