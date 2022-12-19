### 解题思路
先设定盈利为0，最小值为第一天的值，然后用后面的价格和min比较，如果差值小于0，则min等于比较值，如果大于零，盈利 = 差值和盈利中的最大值。

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
   var h = 0;
   var min = prices[0];
   for(var i = 0;i<prices.length-1;i++){
       var c = prices[i + 1] - min;
       if(c < 0) {
          min = prices[i + 1];
       }else {
           h = Math.max(h,c);
       }
   }
   return h;
};
```