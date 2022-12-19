```
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    
    if(prices .length === 0) return 0
    let profit = 0;
    for(let i=1;i<prices.length;i++){
        let now = prices[i] -prices[i-1]
        if(now > 0){
            profit += now
        }
    }
    return profit
};
```
