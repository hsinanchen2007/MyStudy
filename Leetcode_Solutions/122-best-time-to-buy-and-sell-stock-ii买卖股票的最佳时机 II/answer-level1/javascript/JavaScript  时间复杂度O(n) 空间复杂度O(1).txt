```
/**
 * @param {number[]} prices
 * @return {number}
 * 后面的比前面的大就加
 */
var maxProfit = function(prices) {
    let max = 0;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1])
            max += prices[i] - prices[i - 1];
    }
    return max;
};
```