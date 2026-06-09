```
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var ret = 0
    for (var i = 0; i < prices.length; i++) {
        var tmp = prices[i+1] - prices[i]
        // 只要股票上涨的时候就进行交易，下降时候不进行交易
        if (tmp > 0) {
            ret += tmp
        }
    }
    return ret
};
```
