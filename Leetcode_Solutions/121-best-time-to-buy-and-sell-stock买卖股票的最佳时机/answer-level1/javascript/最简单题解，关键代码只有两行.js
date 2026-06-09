

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    //分析动归子问题， 即 prices[i] - prices[i-1] ；
    //循环不变量，目前差值为0
    let a = 0;
    //第一天价值
    let b= prices[0];

    for(let i =1;i<prices.length;i++){
        // 取当天和前一天最小股价；
        b = Math.min(b,prices[i]);
        // 比较取出 （第i天的股价 - 最小股价 : 之前差值）最大值
        a = Math.max(prices[i] - b , a);
    }
    return a;
};
```