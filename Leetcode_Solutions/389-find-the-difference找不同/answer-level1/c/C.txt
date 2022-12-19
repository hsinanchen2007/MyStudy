
### 代码

```c
char findTheDifference(char * s, char * t){
    int m[26] = {0};
    char ret;

    while ((ret = *s++) != '\0') {
        m[ret - 'a']++;
    }

    while ((ret = *t++) != '\0') {
        if (m[ret - 'a']-- == 0)
            break;
    }

    return ret;
}
```