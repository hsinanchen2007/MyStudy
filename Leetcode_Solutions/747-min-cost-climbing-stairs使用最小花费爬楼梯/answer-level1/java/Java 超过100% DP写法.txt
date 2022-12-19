![屏幕快照 2020-01-12 上午10.15.50.png](https://pic.leetcode-cn.com/4e23dd1e5bc5582a65aedf0a345605a2ac5a4e921a3d4976c004820548ef207e-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-12%20%E4%B8%8A%E5%8D%8810.15.50.png)

```
class Solution {
    public int minCostClimbingStairs(int[] cost) {
            if (cost.length == 0) return 0;

            //dp[i]表示最小cost
            int[] dp = new int[cost.length+1];

            dp[0] = 0;

            dp[1] = cost[0];

            for (int i = 2; i < cost.length+1; i++) {
                dp[i] = Math.min(dp[i-1], dp[i-2]) + cost[i-1];
            }

            //也可以开辟length+2个空间，最后一位保存前两个的最小值
            return Math.min(dp[cost.length-1], dp[cost.length]);
    }
}
```
