### 解题思路


### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        if(amount == 0){
            return 0;
        }
        //dp数组里记录的硬币个数
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        for(int i = 0; i < coins.length; i++) if(coins[i] <= amount){
            dp[coins[i]] = 1;
        }

        for(int i = 1; i < amount; i++){
            //当有1，2，5时 从小到大计算（也就是这个位置已经放过硬币了）
            if(dp[i] < Integer.MAX_VALUE){
                for(int j = 0; j < coins.length; j++) if((long)i + coins[j] <= amount) 
                    //这里过程可以： f(1) + 1  f(1)+2 f(1)+5  再多次计算后，每个位置有多种组合结果所以求最小值，
                    dp[i + coins[j]] = Math.min(dp[i] + 1, dp[i + coins[j]]);
            }
        }
        if(dp[amount] == Integer.MAX_VALUE) return -1;
        return dp[amount];
    }
}
```