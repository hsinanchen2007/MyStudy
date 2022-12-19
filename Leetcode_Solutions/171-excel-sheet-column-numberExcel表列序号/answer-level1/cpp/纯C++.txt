### 解题思路
纯C++

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (auto c : s)
        {
            res = res * 26 + (c - 'A' + 1);
        }

        return res;
    }
};
```