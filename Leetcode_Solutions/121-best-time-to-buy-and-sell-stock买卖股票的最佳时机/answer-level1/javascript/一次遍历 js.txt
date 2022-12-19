### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if (!prices || !prices.length || prices.length === 1) return 0;
    let min = Infinity, maxProfit = 0;
    for (let i = 0; i < prices.length; i++) {
        if (prices[i] < min) {
            min = prices[i]
        } else {
            maxProfit = Math.max(maxProfit, prices[i] - min);
        }
    }
    return maxProfit;
};
```