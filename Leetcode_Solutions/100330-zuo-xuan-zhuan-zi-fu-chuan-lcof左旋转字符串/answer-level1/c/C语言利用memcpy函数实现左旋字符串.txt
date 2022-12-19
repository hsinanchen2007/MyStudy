```c
char* reverseLeftWords(char* s, int n){
    int len = strlen(s);
    char* rlw = (char*)malloc((len + 1) * sizeof(char));
    memcpy(rlw, s + n, (len - n) * sizeof(char));
    memcpy(rlw + len -n, s, n * sizeof(char));
    rlw[len] = '\0';
    return rlw;
}
```
