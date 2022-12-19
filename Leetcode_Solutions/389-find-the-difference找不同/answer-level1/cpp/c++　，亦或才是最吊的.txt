### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        if (t.empty() || s.size() != t.size() - 1) {
            return ' ';
        }
        int val = 0;
        for (int i = 0; i < s.size(); ++i) {
            val ^= s[i];
            val ^= t[i];
        }
        val ^= t[t.size() - 1];
        return val;
    }
};
```