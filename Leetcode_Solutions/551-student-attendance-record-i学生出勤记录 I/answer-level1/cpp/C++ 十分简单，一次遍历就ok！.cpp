# C++，如下：

```c++ []
bool checkRecord(string s) {
    int a = 0, l = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'P') l=0;
        else if (s[i] == 'L' && ++l == 3) return 0;
        else if (s[i] == 'A') {
            if(a++) return 0;
            l = 0;
        }
    }
    return 1;
}
```

