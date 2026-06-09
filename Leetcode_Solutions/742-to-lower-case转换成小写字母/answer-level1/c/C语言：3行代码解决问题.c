```
char * toLowerCase(char * str){
    if (str == NULL) return NULL;
    for (int i = 0; str[i]; ++i) if ((64 < str[i]) && (str[i] < 91)) str[i] ^= 0x20;
    return str;
}
```
