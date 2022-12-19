### 思路
看作26进制数。

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size(), res = 0;
        for (int i = 0; i < size; ++i) {
            res += (s[i] - 'A' + 1) * pow(26, size - 1 - i);
        }
        return res;
    }
};
```