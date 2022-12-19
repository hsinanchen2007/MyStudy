### 解题思路
连续上涨和单次上涨就是累加关系
下跌不交易

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let r=0;
    for(let i=0;i<prices.length-1;i++){
        if(prices[i]<prices[i+1]){
            r+=prices[i+1]-prices[i];
        }
    }
    return r;
};
```