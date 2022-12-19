### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let max= 0;
    let min = prices[0] // 记录某天和之前最小股票价格
    for(let i = 1; i< prices.length; i++) {
        min = Math.min(min, prices[i]);
        if( prices[i] - min > 0) max = Math.max(max, prices[i] - min);
    }

    return max
};
```