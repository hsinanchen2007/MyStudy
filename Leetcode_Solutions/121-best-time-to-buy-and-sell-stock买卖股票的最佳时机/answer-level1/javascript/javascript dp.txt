```
var maxProfit = function(prices) {
    const len = prices.length;
    if(len < 1) return 0;
    const hold = [];
    const unhold = [];
    hold[0] = -prices[0];
    unhold[0] = 0;
    for(let i = 1; i < len; i++) {
        hold[i] = Math.max(-prices[i], hold[i - 1]);
        unhold[i] = Math.max(unhold[i - 1], hold[i - 1] + prices[i]);
    }
    return unhold[len - 1];
};
```
