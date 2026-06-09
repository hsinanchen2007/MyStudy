### 解题思路
1、判断特例
2、一个res代表结果，minPrice代表当前轮次遍历到的最小值
3、用当前值 减去 排在它之前最小的值，得到的就是和当前值的最大差值

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    const len = prices.length
    if(len<2) return 0;
    let res = 0, minPrice = prices[0]
    for(let i=1; i<len; i++){
        res = Math.max(res, prices[i] - minPrice)
        minPrice = Math.min(prices[i], minPrice)
    }
    return res
};
```