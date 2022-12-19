### 解题思路
max 记录最大利润
min 记录最小价格
一个for循环解决。

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let max = 0;
    let min = Number.MAX_VALUE;
    for(let i = 0; i < prices.length; i++){
        max = Math.max(max, prices[i] - min);
        min = Math.min(min, prices[i]);
    }
    return max;
};
```