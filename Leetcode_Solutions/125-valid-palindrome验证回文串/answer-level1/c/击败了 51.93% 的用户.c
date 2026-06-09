### 解题思路
1. 双指针一前一后对比

### 代码

```c
bool isPalindrome(char * s){
    int len;
    char *ps, *pe;
    if (s == NULL) return false;

    len = strlen(s);
    ps = s;
    pe = s + len - 1;

    while (ps < pe)
    {
        if (!((*ps >= '0' && *ps <= '9') || 
            (*ps >= 'a' && *ps <= 'z') || 
            (*ps >= 'A' && *ps <= 'Z')))
        {
            ps++;
            continue;
        }
        if (!((*pe >= '0' && *pe <= '9') || 
            (*pe >= 'a' && *pe <= 'z') || 
            (*pe >= 'A' && *pe <= 'Z')))
        {
            pe--;
            continue;
        }
        if (0 != strncasecmp(ps, pe, 1)) return false;

        ps++;
        pe--;
    }
    return true;
}
```