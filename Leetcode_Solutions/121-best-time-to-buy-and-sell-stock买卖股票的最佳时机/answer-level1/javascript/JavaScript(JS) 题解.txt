### 解题思路
动态规划，每天与之前最低价的差值作为利润，返回最大利润即可。循环需要记录最小值 min (初始值为 prices[0])和最大利润 profit (初始值为 -prices[0])。

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    if (!prices.length) return null
    let min = prices[0], profit = -prices[0];
    for (let i = 1; i < prices.length; i++) {
        profit = Math.max(prices[i] - min, profit);
        if (prices[i] < min) min = prices[i];
    }
    return profit <= 0 ? 0 : profit
};
```