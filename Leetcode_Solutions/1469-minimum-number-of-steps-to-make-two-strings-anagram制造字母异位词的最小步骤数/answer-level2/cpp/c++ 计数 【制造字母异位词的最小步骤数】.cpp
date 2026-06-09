### 解题思路
计算s和t中每个字符出现的次数， s和t中所有出现过的字符，s中出现的次数减去t中出现次数大于0的所有项加和就是要求的结果。

### 代码

```cpp
class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            count[s[i] - 'a'] ++;
            count[t[i] - 'a'] --;
        }
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            result += count[i] > 0 ? count[i] : 0;
        }
        return result;
    }
};
```