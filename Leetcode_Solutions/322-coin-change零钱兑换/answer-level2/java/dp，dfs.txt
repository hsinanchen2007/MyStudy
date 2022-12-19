### 解题思路
自底向上的动态规划，dp[i] 表示总金额为i时，在给定coins下，最少数量的硬币组合。dp[i]也可表示为 dp[i-coins[j]]+1，在不同的j情况下取最小值。

贪心+dfs，因求最小值，所以需要尽可能多的使用面额大的硬币，故将coins数组逆序排列，需要k = amount/coins[i]个硬币,下一次递归开始将余额分配给更小面额的硬币，即amount = amount-k*coins[i],i = i+1,如果dfs的过程没找到结果，需要回溯 将k-1，继续dfs。

### 代码

```java
class Solution {
    public int coinChange1(int[] coins, int amount) {
        int[] dp = new int[amount+1];
        Arrays.fill(dp,amount+1);
        dp[0] = 0;
        for(int i = 1;i<=amount;i++){
            for(int j = 0;j<coins.length;j++){
                if(i>=coins[j]){
                    dp[i] = Math.min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
    int ans = Integer.MAX_VALUE;
    public void coinChange(int[] coins,int coinIndex,int amount,int count){
        if(amount==0){
            ans = Math.min(ans,count);
            return;
        }
        if(coinIndex==coins.length) return;
        for(int k = amount/coins[coinIndex];k>=0&&k+count<ans;k--){
            coinChange(coins,coinIndex+1,amount-k*coins[coinIndex],k+count);
        }
    }
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        int [] newCoins = new int[coins.length];
        for(int i = 0;i<newCoins.length;i++){
            newCoins[i] = coins[coins.length-1-i];
        }
        coinChange(newCoins,0,amount,0);
        return ans==Integer.MAX_VALUE?-1:ans;
    }
}
```