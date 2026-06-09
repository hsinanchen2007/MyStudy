### 解题思路
第一步，确定状态
			我们要找到amount的最少硬币，其实要找的就是对应amout减去coins数组中每种硬币的价值之后要凑成的值的最少硬币加一即可，即为此问题的子问题；
第二步，转移方程
			dp[amount] = Math.min(dp[amount - conin[x1]], dp[amount - conin[x2]], ... ,dp[amount - conin[conin.length - 1]]);
第三步，初始条件和边界条件，dp[0] = 0; dp[- x] = Integer.MAX_VALUE
第四步，计算顺序，从前往后，从小到大

注意这里的内层循环是通过和当前amount（代码中的i） - coins得到的值作为dp[]的索引加一（当前次）与原来的使用硬币的个数作比较，初始化值为Integer.MAX_VALUE。

### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        dp[0] = 0;
        int len = coins.length;
        int i, j;
        for(i = 1 ; i <= amount; i ++){
            dp[i] = Integer.MAX_VALUE;
            for(j = 0; j < coins.length; j ++){
                if(i - coins[j] >= 0 &&dp[i - coins[j]] != Integer.MAX_VALUE){
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        if(dp[amount] == Integer.MAX_VALUE){
            return -1;
        }
        return dp[amount];
    }
}
```