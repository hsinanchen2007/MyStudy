### 股票6道
+ 1、[121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
+ 2、[122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
+ 3、[123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/)
+ 4、[309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/)
+ 5、[188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/)
+ 6、[714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/)
## [卍解👇敬请戳看](https://github.com/Alex660/Algorithms-and-data-structures/blob/master/demos/%E8%82%A1%E7%A5%A86%E9%81%93.md)
___
#### 解法一：动态规划
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let n = prices.length;
    if(n == 0){
        return 0;
    }
    let dp = Array.from(new Array(n),() => new Array(2));
    for(var i = 0;i < n;i++){
        if(i == 0){
            dp[0][0] = 0;
            dp[0][1] = -prices[i];
            continue;
        }else if(i == 1){
            dp[1][0] = Math.max(dp[0][0],dp[0][1]+prices[i]);
            dp[1][1] = Math.max(dp[0][1], - prices[i]);
            continue;
        }
        dp[i][0] = Math.max(dp[i-1][0],dp[i-1][1] + prices[i]);
        dp[i][1] = Math.max(dp[i-1][1],dp[i-2][0] - prices[i]);
    }
    return dp[n-1][0];
};
```
#### 解法二：动态规划 - 降维
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let n = prices.length;
    if(n == 0){
        return 0;
    }
    let dp_i_0 = 0;
    let dp_i_1 = -Infinity;
    let dp_pre = 0;
    for(var i = 0;i < n;i++){
        let tmp = dp_i_0;
        dp_i_0 = Math.max(dp_i_0,dp_i_1 + prices[i]);
        dp_i_1 = Math.max(dp_i_1,dp_pre - prices[i]);
        dp_pre = tmp;
    }
    return dp_i_0;
};
```