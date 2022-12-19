### 解题思路

如果s2是s1的转换，则两个s1拼接起来时，s2肯定是s1的子串；

### 代码

```c
bool isFlipedString(char* s1, char* s2){
    int sz1, sz2;
    int i, j;
    char *arr = NULL;

    sz1 = strlen(s1);
    sz2 = strlen(s2);
    if (sz1 != sz2) {
        return false;
    } else if (sz1 == 0) {
        return true;
    }
    
    arr = (char *)malloc(sizeof(char) * (sz1 * 2 + 1));
    memset(arr, 0, sizeof(char) * (sz1 * 2 + 1));
    strcat(arr, s1);
    strcat(arr, s1);
    if (strstr(arr, s2) != NULL) {
        free(arr);
        return true;
    } else {
        free(arr);
        return false;
    }
}
```