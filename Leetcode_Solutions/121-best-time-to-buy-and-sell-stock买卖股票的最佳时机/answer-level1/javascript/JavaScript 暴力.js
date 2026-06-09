```
/**
 * @param {number[]} prices
 * @return {number}
 * 双重循环 时间复杂度 1/2 * n(n - 1)
 */
var maxProfit = function(prices) {
    let max = 0;
    for (let i = 0; i < prices.length - 1; i++) {
        for (let j = i + 1; j < prices.length; j++) {
            if (prices[j] < prices[i])
                continue;
            let diffVal = prices[j] - prices[i];
            if (diffVal >= max) {
                max = diffVal;
            }
        }
    }
    return max;
};
```