### 解题思路
此处撰写解题思路
1.遍历同时记录最大最小值；
2.当遇到最小的值时，将最大值调整为当日的值（即最小的值）；
3.然后比较利润返回。
### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if(!prices.length){return 0;}
    var max=prices[0];
    var min=prices[0];
    var p=max-min;
    for(var i=1;i<prices.length;i++){
        if(prices[i]<min && i!==prices.length-1){
            min=prices[i];
            max=min;
        }
        else{
            max=Math.max(max,prices[i]);
        }
        p=Math.max(p,max-min);
    }
    return p;
};
```