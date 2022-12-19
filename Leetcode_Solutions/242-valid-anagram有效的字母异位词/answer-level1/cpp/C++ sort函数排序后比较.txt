### 解题思路
执行用时52ms，运算比用哈希法慢，但是这样写起来快。。。

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(0 != s.compare(t)) return false;

        return true;
    }
};
```