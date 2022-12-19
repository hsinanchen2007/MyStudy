### 解题思路
只要某一天的价格比后一天的低，就买入，第二天卖掉，总利润加上差值

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    const len = prices.length
    let max = 0
    for (let i = 0; i < len - 1; i ++) {
        if (prices[i] < prices[i + 1]) {
            max += prices[i + 1] - prices[i]
        }
    }
    return max
};
```