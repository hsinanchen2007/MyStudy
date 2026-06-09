### 解题思路
第一次从后往前遍历，记录当前元素后面的最大值
第二次遍历计算最大利润

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    const len = prices.length;
    const maxPrices = new Array(len).fill(0);
    let curMax = 0;
    for(let i = len - 2; i >= 0; i--) {
        if (prices[i + 1] > curMax) {
            curMax = prices[i + 1];
        }
        maxPrices[i] = curMax;
    }
    let max = 0;
    for(let i = 0; i < len; i++) {
        if ( maxPrices[i] - prices[i] > max) {
            max = maxPrices[i] - prices[i];
        }
    }
    return max;
};
```