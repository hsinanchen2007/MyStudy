### 解题思路
这就正常人的思路吧，记录下当下与之前最小值比较的数组，其中最大的那个就是最高利润。没有任何优化，没有奇技淫巧（总感觉我是不是绕弯路了）。

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if (prices.length<=1){
        return 0
    } else {
        let resultArr = []
        prices.forEach((num,index,arr)=>{
        let low = Math.min(...arr.slice(0,index+1))
        let biggestGap = num - low
        resultArr.push(biggestGap)    
})

        return Math.max(...resultArr)
    }
};
```