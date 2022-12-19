### 解题思路
计算当前节点能挣最大的钱，那就要减去前边路过最小的值
然后路过每个节点，比较并记录下能挣到最大的钱

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let min = prices[0]
    let temp = Number.MIN_VALUE
    for(let i =0;i < prices.length ;i++){
        if(prices[i] < min){
            min = prices[i]  
        }
        let cur = prices[i] - min
        temp = Math.max(temp,cur)
    }
    return temp
};
```