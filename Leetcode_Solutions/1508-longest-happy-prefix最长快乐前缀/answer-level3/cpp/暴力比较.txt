用string各种内存超标，换成char*就ok了
```
class Solution {
public:
    string longestPrefix(string s) {
        int l = s.length();
        const char *s1 = s.c_str();
        const char *s2 = s.c_str();
        for (int i = l - 1; i > 0; i--) {
            if (s1[i - 1] != s1[l - 1]) {
                continue;
            }
            if (strncmp(s1, s2 + l - i, i) == 0) {
                return s.substr(0, i);
            }
        }
        return "";
    }
};
```

