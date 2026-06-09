n个A指令可以走到位置2^n-1，执行一次R即为反向。
通过log2(target)求出n后，两种情况：
1. 如果target正好为2^n-1，则执行n次A即可；
2. 不正好的话，有两种走法：
    a. 直接前进通过target：n次A走到(2^n-1),然后1次R反向，递归走剩余的(2^n-1-target);
    b. 前进直到下一次会通过target：n-1次A走到(2^(n-1)-1)，然后1次R反向，反向走m个A，再1次R反向，递归走剩余的(target-(2^(n-1)-1-2^m))。
```
#include <math.h>
class Solution {
public:
    int dp[10001];
    int racecar(int target) {
        if (dp[target] > 0) return dp[target];
        int n = floor(log2(target)) + 1;
        if (target + 1 == (1<<n)) {
            dp[target] = n;
        } else {
            // n个A到达2^n-1位置，然后R反向，走完剩余
            dp[target] = n + 1 + racecar((1<<n) - 1 - target);
            // n-1个A到达2^(n-1)-1位置，然后R反向走m个A，再R反向，走完剩余
            // m取值遍历[0, n-1)
            for (int m = 0; m < n-1; ++m) {
                dp[target] = std::min(dp[target], n + m + 1 + racecar(target - (1<<(n - 1)) + (1<<m)));
            }
        }
        return dp[target];
    }
};
```
