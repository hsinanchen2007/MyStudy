### 解题思路
动态规划
由于可以跳1或者2，因此最终的结果要么跳在最后一个台阶上，要么跳过最后一个台阶一个，因此需要考虑跳出最高台阶一个的情况时的花费。
当计算落在原数组长度之外的台阶上时，此时这个台阶没有花费，因此此时无需进行+操作（即i == length时）。

### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int length = cost.length;
        // int[] dp = new int[length + 1];
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // dp数组可以优化为两个int数字
        int dp0 = cost[0];
        int dp1 = cost[1];
        for (int i = 2; i <= length; i++) {
            int tmp = Math.min(dp0, dp1);
            dp0 = dp1;
            dp1 = (i < length) ? tmp + cost[i] : tmp;
            // dp[i] = Math.min(dp[i - 1], dp[i - 2]);
            // if (i < length) {
            //     dp[i] += cost[i];
            // }
        }

        return Math.min(dp0, dp1);
    }
}
```