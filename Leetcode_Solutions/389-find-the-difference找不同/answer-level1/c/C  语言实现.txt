C  语言实现
```C []
char findTheDifference(char * s, char * t){
    char res = 0;
    while (*s) res ^= ((*s++) ^ (*t++));
    return (res ^ (*t));
}

```