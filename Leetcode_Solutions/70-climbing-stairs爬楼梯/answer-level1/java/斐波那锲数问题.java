经典的斐波那锲数问题。可以从第(n-1)级台阶或者(n-2)级台阶跳到第n级台阶。
因此状态转移方程为f(n) = f(n-1)+f(n-2)

```
public int climbStairs(int n) {
        if (n < 1) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return n;
        }
        int a = 1;
        int b = 2;
        int res = 0;
        for (int i = 2; i < n; i++) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
```
## [更多leetcode题解参考此处](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)