```
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if (cost.length == 0)
            return 0 ;
        if (cost.length == 1)
            return 0 ;
        // 终点是第i个楼梯的最小体力花费
        int[] dp = new int[cost.length+1] ;
        dp[0] =cost[0]  ;
        dp[1] =cost[1] ;

        for (int i=2 ; i <= cost.length ; i++) {
            dp[i] = Math.min(dp[i-1] ,dp[i-2]) + ( i<cost.length ? cost[i] : 0 ) ;
        }
        return dp[cost.length] ;
    }
}
```
