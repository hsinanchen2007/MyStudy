### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let maxValue = 0;
    let buyPrice = prices[0];
    for (let i = 1; i < prices.length; i++) {
        let price = prices[i];
        if (price > buyPrice) {
            maxValue = Math.max(price - buyPrice, maxValue);
        } else if (price < buyPrice) {
            buyPrice = price;
        }
    }
    return maxValue;
};
```