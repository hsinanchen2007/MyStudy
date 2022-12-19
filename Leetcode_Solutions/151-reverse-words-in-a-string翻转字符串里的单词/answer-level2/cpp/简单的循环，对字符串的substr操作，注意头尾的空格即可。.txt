### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int length = 0;
        string res = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (length == 0) {
                    continue;
                } else {
                    res += s.substr(i + 1, length) + " ";
                    length = 0;
                }
            } else {
                length++;
            }
        }
        if (length != 0) {
            res += s.substr(0, length) + " ";
        }
        return res.substr(0, res.size() - 1);
    }
};
```