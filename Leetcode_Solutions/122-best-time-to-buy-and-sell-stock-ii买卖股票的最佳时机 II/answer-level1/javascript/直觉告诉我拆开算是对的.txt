大上升线段等于小上升线段之和
```
var maxProfit = function(prices) {
    let sum=0;
    for(let i=1;i<prices.length;i++){
        if(prices[i]>prices[i-1]){
            sum+=prices[i]-prices[i-1]
        }
    }
    return sum;
};
```
