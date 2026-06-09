### 解题思路
需要注意边界条件。负数取余仍然是负数。

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        //bool is_neg = x > 0 ? false : true;
        //x = x > 0 ? x : -x;
        int re = 0;
        while(x != 0) {
            int a = x % 10;
            x /= 10;
            if (re > INT_MAX/10 || re < INT_MIN/10)
                return 0;
            re = re*10 + a;
        }
        return re;
    }
};
```