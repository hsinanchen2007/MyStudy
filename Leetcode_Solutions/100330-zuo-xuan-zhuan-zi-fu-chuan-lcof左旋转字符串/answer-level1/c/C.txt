```
char* reverseLeftWords(char* s, int n){
    int len = strlen(s);
    char* arr = (char*)malloc(sizeof(char) * (len + 1));
    int i = 0;
    for (; i < strlen(s); i++) {
        arr[i] = s[(i + n) % (len)];
        printf("%c ", arr[i]);
    }
    arr[i] = '\0';   
    return arr;
}
```
