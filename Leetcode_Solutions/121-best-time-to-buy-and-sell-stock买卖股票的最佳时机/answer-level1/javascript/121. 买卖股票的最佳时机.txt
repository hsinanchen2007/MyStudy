### 解题思路

1. 找到一个较小的值 ``prev``，如果找不到，继续找
2. 满足 1 的条件之后，找到一个较大的值，满足 $prices[i] - prev > curr$，说明此时卖出股票是能盈利的，且利润比上一次买卖的策略大

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let curr = 0
    let prev = Number.MAX_SAFE_INTEGER
    for (let i = 0; i < prices.length; i++) {
        if (prices[i] < prev) {
            prev = prices[i]
        } else if (prices[i] - prev > curr) {
            curr = prices[i] - prev
        }
    }
    return curr
};
```