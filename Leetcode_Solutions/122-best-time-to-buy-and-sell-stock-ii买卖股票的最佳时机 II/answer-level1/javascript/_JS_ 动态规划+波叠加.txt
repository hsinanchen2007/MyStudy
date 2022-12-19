### 解题思路
题意即只要有赚，就交易：只转差价

### 波叠加
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var max = 0;
    for (var i = 1; i < prices.length; i++) {
        if (prices[i] - prices[i - 1] > 0) {
            max += prices[i] - prices[i - 1]
        }
    }
    return max;
};
```
### 解题
当前状态有：持有现金dp[i][0]、持有股票dp[i][1]；
如果持有现金，则可能昨天也持有现金dp[i-1][0]或者昨天持有股票并卖出，取得收益dp[i-1][1]+prices[i];
如果持有股票，则可能昨天也持有股票dp[i-1][1]或者昨天花掉现金，买入股票dp[i-1][0]-prices[i];
### 动态规划

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var dp = [
        []
    ];
    if(prices<1){
        return 0;
    }
    dp[0][0] = 0; // 持有现金
    dp[0][1] = -prices[0]; // 持有股票
    for (var i = 1; i < prices.length; i++) {
        if (!dp[i]) {
            dp[i] = [];
        }
        dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i])
        dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[prices.length - 1][0]
};
```