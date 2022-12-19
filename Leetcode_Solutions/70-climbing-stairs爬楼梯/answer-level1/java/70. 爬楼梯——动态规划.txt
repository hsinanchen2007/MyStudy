### 解题思路
刚开始在纸上随便计算了一下（每层楼梯需要多少种方法）
|   1   |  2    |   3   |   4   |   5   |  6    |   7   |   8   |   9   |   10   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|   1   |   2   |   3   |   5   |   8   |   13  |   21   |   34   |  55    |   89   |


很明显这个结果满足公式$f(n)=f(n-1)+f(n-2),n>2;$

那么直接动态规划，上代码

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int dp[] = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
```