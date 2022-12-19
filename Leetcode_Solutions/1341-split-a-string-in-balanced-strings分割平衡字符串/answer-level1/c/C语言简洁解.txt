```
int balancedStringSplit(const char* s) {
    int res = 0;
    int count = 0;

    int i = 0;
    while (s[i])
    {
        s[i++] == 'R' ? ++count : --count;
        if (!count)
        {
            ++res;
        }
    }

    return res;
}
```
