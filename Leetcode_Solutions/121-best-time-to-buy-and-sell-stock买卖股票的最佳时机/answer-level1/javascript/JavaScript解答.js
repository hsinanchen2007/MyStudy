### 解题思路
遍历数组，每次移动指针i，记录两个值，min记录目前为止的（0-i）最低价位，max记录目前为止的最大利润（计算如果在目前为止的最低价位买入，并在当前位置抛出，能获得多大利润，如果比max大，则更新max）

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let max=0,min=prices[0];
    for(let i=1;i<prices.length;i++){
        min=Math.min(prices[i],min);
        max=Math.max(prices[i]-min,max);
    }
    return max;
};
```