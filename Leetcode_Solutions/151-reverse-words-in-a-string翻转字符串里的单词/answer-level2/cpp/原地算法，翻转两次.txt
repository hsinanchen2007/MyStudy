### 解题思路
遇到的坑：
1. 不要轻易在循环内部对迭代器进行修改，可能会跳过一些关键语句

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string::iterator left = s.begin();
        while (*left == ' ') {
            left = s.erase(left);
        }
        for (int i=0; i<=s.size(); i++) {
            if (i == s.size()) {
                reverse(left, s.end());            
            }
            else if (s[i] == ' ') {
                reverse(left, s.begin()+i);
                left = s.begin()+i+1;
                while (*left == ' ') {
                    left = s.erase(left);
                }
                i = left-s.begin();
            }
        }
        if (*(s.end()-1) == ' ') 
            s.erase(s.end()-1);    
        return s;
    }
};
```