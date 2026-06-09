### 思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int len = 0, end = s.size() - 1;
        while (s[end] == ' ') --end;
        while (end >= 0 && isalpha(s[end])) {
            ++len, --end;
        } 
        return len;
    }
};
```