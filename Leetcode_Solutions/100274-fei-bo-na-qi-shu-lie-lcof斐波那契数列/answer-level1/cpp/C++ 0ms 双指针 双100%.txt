### 解题思路
a和b依次向后移动，中间变量t辅助

### 代码

```cpp
class Solution {
public:
    int fib(int n)
    {
        int a = 0, b = 1, t;
        if (n == 0) return 0;
        if (n == 1) return 1;
        for (int i = 2; i <= n; i++)
        {
            t = a;
            a = b;
            b = t + b;
            if (b > 1000000007) b %= 1000000007;
        }
        return b;
    }
};
```