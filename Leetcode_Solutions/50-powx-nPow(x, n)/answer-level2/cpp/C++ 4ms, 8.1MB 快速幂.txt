### 解题思路
快速幂模板题

![image.png](https://pic.leetcode-cn.com/02661151ab594a538abe78e9184f6b660259c412add23d1ff1888c9810bb8916-image.png)

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        // 特殊情况处理
        if(n == 0) return 1;
        if(x == 0) return 0;
        double ans = 1;
        // 因为 n 为负时最小可达-2147483648，直接取反时超过int上限，因此特殊处理
        if(n < 0)
        {
            x = 1 / x;
            ans = x;
            n = -(n + 1);
        }
        // 快速幂
        while(n > 0)
        {
            if(n % 2 > 0) ans *= x;
            n /= 2;
            x = x * x;
        }
        return ans;
    }
};
```