method 1:  subtraction
```
class Solution {
    public:
        char findTheDifference(string s, string t) {
            int len = s.length();
            char res = 0;
            for (int i = 0; i < len; i++) {
                res += t[i] - s[i];
            }
            res += t[len];
            return res;
        }
};
```

method2: xor

```
class Solution {
    public:
        char findTheDifference(string s, string t) {
            int len = s.length();
            char res = t[len];
            for (int i = 0; i < len; i++) {
                res ^= (s[i] ^ t[i]);
            }
            return res;
        }
};
```
