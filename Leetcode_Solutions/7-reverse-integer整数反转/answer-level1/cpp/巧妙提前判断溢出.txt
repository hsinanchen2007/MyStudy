### 解题思路
提前一位判断

### 代码

```cpp
class Solution {
public:
    int reverse(int x)
    {
        int res = 0;
        int sup = INT_MAX / 10, inf = INT_MIN / 10;
        while (x)
        {
            if (res > sup || res < inf) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
```