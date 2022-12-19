### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    // 找出所有的涨的空间
    let result = 0;
    for (let i=0; i < prices.length - 1; i++) {
        let tomorrowCanGet = prices[i+1] -prices[i];
        if (tomorrowCanGet > 0) {
            result += tomorrowCanGet;
        }
    }
    return result;
};
```