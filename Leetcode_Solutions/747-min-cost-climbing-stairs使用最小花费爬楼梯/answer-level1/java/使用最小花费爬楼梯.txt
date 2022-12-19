### 解题思路
题目非常费解，要求的是跨出数组外。
要跨出一个n阶的阶梯，可以从第n阶跨出去，也可以从第n-1阶跨出去。
再加上为了爬到（还没踏上去）n阶和n-1阶需要的体力，就可以得到答案。
创建一个数组dp[]，dp[i]表示爬到（还没踏上去）第i阶需要的体力。
对n阶阶梯，答案正好就是爬到（还没踏上去）第n阶需要的体力，也就是dp[n]。
注意一点，因为第1、2阶可以直接选择，所以爬到（还没踏上去）是毫不费力的，因此dp[0]、dp[1]都为0。而这样的话n == 1时直接返回dp[1] == 0是不对的，所以需要做特殊处理。

### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        if (n == 1) {
            return cost[0];
        }
        int dp[] = new int[n + 1];
        for (int i = 2; i < n + 1; i++) {
            dp[i] = Math.min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[n];
    }
}
```