```
bool isFlipedString(char* s1, char* s2){

    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    int len = strlen(s1);
    int i = 0;
    char* arr = (char*)malloc(sizeof(char) * len * 2 + 1);
    for (; i < 2 * len; i++) {
        arr[i] = s1[i % len];
        //printf("%c ", arr[i]);
    }
    arr[i] =  '\0';
    if (strstr(arr, s2) != NULL){
        return true;
    }

    return false;
}
```
