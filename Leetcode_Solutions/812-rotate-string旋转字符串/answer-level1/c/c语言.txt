### 解题思路
c语言

### 代码

```c
bool rotateString(char * A, char * B){
    int aLen =  strlen(A);
    int bLen = strlen(B);
    char *temp = (char *)calloc((2 * aLen + 1), sizeof(char));
    char *res = NULL;

    if (aLen != bLen) {
        return false;
    }
    strcpy(temp, A);
    strcat(temp, A);
    res = strstr(temp, B);
    if (res != NULL) {
        return true;
    }
    return false;
}
```