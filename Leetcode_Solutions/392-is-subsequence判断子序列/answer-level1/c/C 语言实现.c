C 语言实现
```C []
bool isSubsequence(char * s, char * t){
    while (*t) {
        if (0 == *s)
            return true;
        else if (*s == *t) {
            ++s;
            ++t;
        } else
            ++t;
    }
    return 0 == *s;
}
```