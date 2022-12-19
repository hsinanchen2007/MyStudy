使用贪婪算法思维，在遍历过程中，每次都保存更新当前步骤最大收益值，直到遍历结束即可。


```js
var maxProfit = function(prices) {
    let min = prices[0]
    let range = 0
    for(let i=0; i<prices.length; i++){
        min = Math.min(prices[i], min)
        range = Math.max(prices[i] - min, range) 
    }
    return range
};
```
