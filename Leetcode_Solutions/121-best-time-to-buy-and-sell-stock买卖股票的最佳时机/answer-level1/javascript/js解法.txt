```js
var maxProfit = function(prices) {
    let n = Number.MAX_SAFE_INTEGER, max = 0
    for(let i = 0; i < prices.length; i++) {
        n = Math.min(n, prices[i])
        max = Math.max(max, prices[i] - n)
    }
    return max
};
```