### 解题思路
1.串联两个字符串，若能够在长字符串中能够找到字符串且起始位置等于字符串的长度即表示是可有重复的子字符串表示的。
2.因为如果查找到字符串的起始位置是字符串长度话表示在这个长字符串中仅有这个字符串重复的2次。

### 代码

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
```