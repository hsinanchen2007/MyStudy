### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let max = 0;
    for(let i = 0;i < prices.length;i ++) {
        for(let j = i + 1;j < prices.length;j ++) {
            const profit = prices[j] - prices[i];
            if(profit > max) {
                max = profit;
            }
        }
    }
    return max;
};
```