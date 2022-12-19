题目其实有个地方我感觉没有说的很清楚，就是最顶的阶梯不是数组最后一个元素，而是之外

#### 解题思路
利用动态规划，先找出**状态**和**选择**
状态就是到每一阶的消耗的最小值，选择就是是从上一级到这一级还是上上一级到这一级，

dp[0] 应该等于cost[0],表示选择这一级的最小值，
`dp[1] = Math.min(dp[0] + cost[1], cost[1]);`
表示跳到第二级消耗能量的最小值，是从第一级跳过来比较小还是直接跳到这一级比较小，

然后就可以写出状态方程，
`dp[i] = Math.min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);`

但这个到最后的话表示的还不是到最上一层消耗的能量，还要给dP数组增长1，储存到最上一层的最小值。


``` java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        //判断特殊值
        if(cost.length == 2)
            return cost[1];
        //申请数组时长度应该要比cost大1
        int []dp = new int[cost.length + 1];
        dp[0] = cost[0];
        dp[1] = Math.min(dp[0] + cost[1], cost[1]);
        for(int i = 2; i < cost.length; i++) {
            dp[i] = Math.min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
        }
        //储存最高一级消耗最小的能量
        dp[cost.length] = Math.min(dp[cost.length - 1], dp[cost.length - 2]);
        return dp[cost.length];
    }
}
```
