两种方法
1、暴力法，两层for循环
```
var maxProfit = function(prices) {
    var max = 0
    for(var i = 0 ; i< prices.length ;i++){
        for(var j = i+1 ; j < prices.length ;j++){
            if(prices[j] - prices[i] < 0){
                continue
            }else{
                max = Math.max(max ,prices[j] - prices[i])
            }
        }
    }
    return max
};
```
2、简化版
```
var maxProfit = function(prices) {
    var buy = prices[0]
    var profit = 0
    for(var price of prices){
        buy = Math.min(buy , price)
        profit = Math.max(profit , price- buy)
    }
    return profit
};
```
