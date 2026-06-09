### 解题思路
第一种方法没什么好说的，
想着方法以两层循环，空间复杂度就增加了一倍，所以就用方法二想着性能会有所优化，结果检测方法2比方法1还消耗性能，
大佬有更好的方法，求教

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
<!-- （1） -->
var maxProfit = function(prices) {
    var max=0, a;
    for(let i=0;i<prices.length;i++){
        for(let j=i+1; j<prices.length;j++){
            a=prices[j]-prices[i];
            max=Math.max(max, a);
        }
    }
    return max;
};
<!-- （2） -->
// var maxProfit = function(prices) {
//     var lastMax=0, a;
//     for(let i=0;i<prices.length;i++){
//         let arr=prices.slice(i, prices.length);
//         let max= Math.max(...arr);
//         a=max-prices[i];
//         lastMax=Math.max(lastMax, a);
//     }
//     return lastMax;
// };
```