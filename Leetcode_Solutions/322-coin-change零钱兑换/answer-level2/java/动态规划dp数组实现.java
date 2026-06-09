### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        int dp[] = new int[amount+1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;
        for(int i = 1; i < dp.length; i++){
            for(int coin: coins){
                if(i - coin >= 0 && dp[i] > dp[i-coin] + 1){
                    dp[i] = dp[i-coin] + 1;
                }
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
}
```