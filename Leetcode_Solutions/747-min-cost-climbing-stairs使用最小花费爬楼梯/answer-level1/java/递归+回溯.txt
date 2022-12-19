### 解题思路
此处撰写解题思路

### 代码

递归加回溯，但是还是不如动态规划快。

```java
class Solution {
    public int minCostClimbingStairs(int[] cost){
        int number = cost.length-1;
        int[] dp = new int[cost.length];
        Arrays.fill(dp,-1);
        return Math.min(result(cost, number, dp), result(cost, number-1,dp));
    }

    public int result(int[] cost, int number, int[] dp){
        if(number == 0 || number == 1) return cost[number];
        if(dp[number] != -1 ) return dp[number];
        else{
            dp[number] = cost[number] + Math.min(result(cost,number-1, dp), result(cost, number-2, dp));
            int decision = dp[number];
            return decision;
        }

    }
}
```