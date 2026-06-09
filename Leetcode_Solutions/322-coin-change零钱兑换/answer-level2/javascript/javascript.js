```
var coinChange = function(coins, amount) {       
    const dp = new Array(amount + 1).fill(amount + 1);;  
    dp[0] = 0;
    const len = coins.length;
    let j;
    for (let i = 1; i <= amount; i++) {
        j = len;
        while(j--) {
            if (coins[j] <= i) {
                dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
};
```
