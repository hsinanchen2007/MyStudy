### 思路一：暴力
从第一个字符开始查找与第一个字符相等的位置，然后计算子串的长度，如果字符串长度不是子串的长度的整数倍，则判断下一个可能的子串，否则从当前相等位置依次判断后面字符是否和第一个子串对应位置相等，这里通过模运算来计算当前字符对应第一个子串中的位置。如果遍历完所有字符串，则返回true，否则返回false。


### 代码

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        for (int i = 1; i < size; ++i) {
            if (s[i] == s[0]) {
                int len = i, j;
                if (size % len != 0) continue;
                for (j = i; j < size; ++j) {
                    if (s[j] != s[j % len]) break;
                }
                if (j == size) return true;
            }
        }
        return false;
    }
};
```