## 思路
### 代码
```c++
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }                
        int i = 0, j = s.size() - 1;        
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            } else if (!isalnum(s[j])) {
                --j;
            } else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};
```
#### 另一种写法
```c++
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }        
        int size = s.size();
        int i = 0, j = size - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (i < j) {
            while (i < j && !isalnum(s[i])) {
                ++i;
            }
            while (i < j && !isalnum(s[j])) {
                --j;
            }
            if (s[i] != s[j]) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};
```

