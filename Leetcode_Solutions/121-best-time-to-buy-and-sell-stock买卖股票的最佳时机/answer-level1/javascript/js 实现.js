```
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    
    let min = prices[0];// 默认第一天是最低点买入
    let profit = 0;// 利润为0
    for(let i=1;i<prices.length;i++){
        if(prices[i]>prices[i-1]){
            profit = Math.max(profit,prices[i]-min)
        }else{
            min = Math.min(min,prices[i])
        }
    }
    return profit

};
```
