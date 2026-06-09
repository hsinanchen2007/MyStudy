
### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if(!prices.length) return 0;
    let p = q = prices[0];
    let res = 0;
    for(let i = 1;i< prices.length; i++){
        if(prices[i] < p) {
            p = q = prices[i];
            continue;
        }
        if(prices[i] > q){
            q = prices[i];
            res = q - p > res ? q - p : res;
        }
    }
    return res;
};
```