### 解题思路
遍历的同时找最低的价格和最大差值 遍历完即可

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    // 找最小价格和最大利润
    let lowestPrice = prices[0]
    let maxProfit = 0
    for(let i=0;i<prices.length;i++){
        if(prices[i]<lowestPrice){
            lowestPrice = prices[i]
        }
        if(prices[i]-lowestPrice>maxProfit){
            maxProfit = prices[i] - lowestPrice
        }
        
    }
    return maxProfit

};
```