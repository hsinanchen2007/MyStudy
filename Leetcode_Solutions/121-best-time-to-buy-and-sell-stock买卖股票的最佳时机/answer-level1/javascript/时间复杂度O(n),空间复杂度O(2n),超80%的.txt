### 解题思路
此处撰写解题思路

### 代码
分别定义
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */

const maxProfit = function(prices) {
  let min = prices[0];
  let profit =0;
  for (let i = 0; i < prices.length; i++) {
      min=Math.min(min,prices[i])
      profit=Math.max(prices[i]-min,profit)
  }
  return profit;
};
```