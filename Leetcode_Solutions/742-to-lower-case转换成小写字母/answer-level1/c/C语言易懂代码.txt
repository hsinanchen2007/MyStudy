```c
char * toLowerCase(char * str){
    if(!str || !str[0])
        return NULL;
        
    int i = 0;
    while (str[i])
    {
        //发现是大写字母则转小写
        if(str[i] <= 'Z' && str[i] >= 'A')
            str[i] += ' ';
        i++;
    }
    return str;
}
```
