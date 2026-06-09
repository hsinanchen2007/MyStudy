### 解题思路
这道题并不难，我也不懂为什么难度级别是中等。。。

直接看代码吧~一看就会

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    //此问题的实质就是找到两个差值最大的数，前提是小的在前，大的在后
    //要把此问题的时间复杂度控制在O(n-1)并不难
    let profits = 0;
    let min = prices[0];
    const len = prices.length;
    for(let i = 1; i < len; i ++) {
        min = Math.min(min, prices[i]);
        profits = Math.max(profits, prices[i] - min);
    }
    return profits;
};
```