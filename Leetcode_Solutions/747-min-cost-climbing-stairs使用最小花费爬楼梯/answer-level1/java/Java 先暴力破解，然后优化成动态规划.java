### 解题思路
我们先用暴力递归思路来写，这个就很简单了代码如下。然后将其优化为动态规划，这个递归函数中唯一变化的是cost的后面的下标，并且base情况也知道了，那么对于dp里面的初始状态，然后是转移函数，对于递归代码里面的非base情况的代码，那么就可以写出对于的dp解法。
```java []
//java递归暴力
public static int minCostClimbingStairs(int[] cost) {
     return minCostClimbingStairs(cost, cost.length-1);
}

public static int minCostClimbingStairs(int[] cost, int end){
    if(end <= 0)
        return 0;
    if(end == 1)
        return Math.min(cost[0], cost[1]);
    return Math.min(cost[end]+minCostClimbingStairs(cost, end-1),
            cost[end-1] + minCostClimbingStairs(cost, end-2));
}
```
```java []
//dp解法
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if(cost == null || cost.length <= 0)
            return 0;
        int[] dp = new int[cost.length];
        for(int i=1; i<cost.length; i++)
            if(i == 1)
                dp[i] = Math.min(cost[0], cost[1]);
            else {
                dp[i] = Math.min(dp[i-1] + cost[i], cost[i-1]+dp[i-2]);
            }
        return dp[dp.length-1];
    }
}
```
