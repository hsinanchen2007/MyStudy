倒序找峰值、谷值，每一个新的峰值诞生，之前的则为最大差值；个人觉得比正序找谷峰值少一些判断
```
// 72ms 35.8mb
var maxProfit = function(prices) {
    let len = prices.length
    if(!len) return 0
    let res = 0, minPrice = prices[len-1], maxPrice = prices[len-1]
    for(let i = prices.length - 1; i > 0 ; i--){
        if(prices[i-1] < prices[i] && prices[i-1] < minPrice){
            minPrice = prices[i-1]
        }else{
            if(maxPrice - minPrice > 0){
                res += maxPrice - minPrice
            }
            maxPrice = prices[i-1]
            minPrice = prices[i-1]
        }
    }
    return res += (maxPrice - minPrice)
};
```
