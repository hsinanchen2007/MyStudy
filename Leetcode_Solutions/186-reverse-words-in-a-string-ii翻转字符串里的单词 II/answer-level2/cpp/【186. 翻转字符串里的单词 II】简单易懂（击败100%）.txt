## 思路
先整体反转，再逐个单词反转。
### 代码
```c++
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int size = s.size(), i = 0;
        while (i < size) {
            while (i < size && s[i] == ' ') ++i;
            int j = i;
            while (i < size && s[i] != ' ') ++i;
            reverse(s.begin() + j, s.begin() + i);
        }
    }
};
```

