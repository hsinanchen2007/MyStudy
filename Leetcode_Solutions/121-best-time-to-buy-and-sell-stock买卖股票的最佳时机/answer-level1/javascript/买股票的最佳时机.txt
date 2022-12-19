1. 暴力破解
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
      if(prices.length < 2) return 0;
      let max = prices[1] - prices[0];
      for(let i = 0; i < prices.length; i++) {
            for(let j = i+1; j < prices.length; j++) {
                max = Math.max(max,prices[j]-prices[i]);
            }
       }
       return max < 0 ? 0 : max;
};
```
时间复杂度：O(n^2)。循环运行 n(n−1)/2 次。
空间复杂度：O(1)

2.  动态规划
只需要找到股票的最低点买入，然后求在最低点买入之后的最大值就行了
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
let minPrice = Infinity;
    if(prices.length < 2) return 0;
    let max = prices[1] - prices[0];
    let min = Infinity;
    for(const price of prices) {
        min = Math.min(min,price);
        max = Math.max(max,price - min)
    }
    return max < 0 ? 0 : max;
}
```
时间复杂度：O(n)，只需要遍历一次。
空间复杂度：O(1)，只使用了两个变量。