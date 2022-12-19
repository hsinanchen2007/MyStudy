/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/10
 *
 * 解题思路: 这道题使用动态规划 主要原因 可以划分为子问题并且子问题之间有关联 假设S[i]表示当前第i个台阶的最小耗费 则有 dp[i] = Math.min(dp[i-1],dp[i-2]) + cost[i];
 *
 * 其余的考虑一下初始0 1 即可 最终返回Math.min(dp[cost.length - 1] , dp[cost.length-2]) 因为到达最终的台阶有两种方式 一步 或者 两步
 *
![746.PNG](https://pic.leetcode-cn.com/a08302f6ce16b5554d13ca5fcee4fb7ef5d87ca544c0cd5413f7be4a4797e0a7-746.PNG)

 */
```
 public int minCostClimbingStairs(int[] cost) {
    int[] dp = new int[cost.length];

    for(int i = 0;i < dp.length;i++){
        if(i < 2){
            dp[i] = cost[i];
        }else{
            dp[i] = Math.min(dp[i-1],dp[i-2]) + cost[i];
        }
    }

    return Math.min(dp[cost.length - 1] , dp[cost.length-2]);
}
```