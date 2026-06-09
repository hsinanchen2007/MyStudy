![image.png](https://pic.leetcode-cn.com/4c08790822b00369d0fd5068df42a885a472136c879a2432657945d7ac1c5721-image.png)

### 解题思路
```js
  分析状态：
  今天手里没有股票：
    1. 昨天就没有，今天也没有购买
    2. 昨天持有，今天刚出售掉
  今天手里持有股票：
    1. 昨天就持有，今天没有出售
    2. 昨天没有，今天刚购买的
```

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */

var maxProfit = function(prices) {
  let dp = [];
  for (let i = 0; i < prices.length; i++) dp[i] = [];
  
  // 初始化 -1 天的时候的基本状态
  dp[-1] = [];
  dp[-1][0] = 0;
  dp[-1][1] = -prices[0];
  
  for (let i = 0; i < prices.length; i++) {
    dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
  }
  
  return dp[prices.length - 1][0];
};
```