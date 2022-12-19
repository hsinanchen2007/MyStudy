# 代码：
```
char* replaceSpace(char* s){
    char  *newans = malloc(sizeof(char) * 10000);
    int i = 0;

    while(*s != '\0'){
        if(*s == ' '){
            newans[i++] = '%';
            newans[i++] = '2';
            newans[i++] = '0';
        }else{
            newans[i++] = *s;
        }
        s++;
    }
    newans[i] = '\0';

    return newans;
}
```

