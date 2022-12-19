### 解题思路
/**
  1. 找状态
       dp[i][0]  表示第 i 天 没有持有  股票得最大利润
       dp[i][1]  表示第 i 天 持有      股票时得最大利润
  2. 状态转移
       dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
       dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
                                   这里 i-2 是因为有冷冻期，前一天不能买，只能在 i-2 那天卖出，然后才可以买 
  3. 初始状态
        dp[0][0] = 0;
        dp[0][1] = -price[0];  
  4. 顺序
     从小到大
 */

### 代码

```javascript
var maxProfit = function(prices) {
    let len = prices.length;
    let dp = [];
    let i;
    if(prices.length <= 1){
        return 0;
    }
    for(i = 0; i<len; i++){
        dp[i] = [];
    }
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[1][0] = Math.max(prices[1]-prices[0], 0);
    dp[1][1] = Math.max(dp[0][1], dp[0][0]-prices[1]);
    for(let i = 2;i<len;i++){
        dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = Math.max(dp[i-1][1], dp[i-2][0] - prices[i]);
    }
    return dp[len-1][0];
};
```