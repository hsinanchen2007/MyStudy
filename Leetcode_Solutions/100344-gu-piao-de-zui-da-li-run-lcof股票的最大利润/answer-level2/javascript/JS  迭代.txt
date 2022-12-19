### 代码

```javascript

var maxProfit = function(prices) {
    let profit = 0;
    let price = Infinity;
    for(let i = 0; i < prices.length; i++){
        price = Math.min(price, prices[i]);
        profit = Math.max(profit, prices[i] - price);
    }
    return profit 
};
```