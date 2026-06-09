## 思路
### 代码
```c++
class Solution {
public:
    string reverseWords(string s) {        
        int size = s.size(), i = 0;
        while (i < size) {
            while (i < size && s[i] == ' ') ++i;
            int j = i;
            while (i < size && s[i] != ' ') ++i;
            reverse(s.begin() + j, s.begin() + i);
        }
        return s;
    }
};
```
