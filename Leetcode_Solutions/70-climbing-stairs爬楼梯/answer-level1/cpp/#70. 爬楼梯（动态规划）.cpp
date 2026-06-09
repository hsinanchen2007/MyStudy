### 状态转移方程
```cpp
f(1) = 1
f(2) = 2
f(n) = f(n-1) + f(n-2)
```

### 代码
```cpp []
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int pre = 1, cur = 2;
        for (int i = 3; i < n; i++) {
            int tmp = cur;
            cur += pre;
            pre = tmp;
        }
        return cur+pre;
    }
};
```