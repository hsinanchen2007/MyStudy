```
char * toLowerCase(char * str){
    char *a=str;
    while(*str)
    {   int i = (int)*str;
        *str++ += i >= 65 && i <= 90?32:0;
    }
    return a;
}
```
暂时还想不到更短的
