执行用时 :72 ms, 在所有 JavaScript 提交中击败了98.72%的用户
内存消耗 :38.2 MB, 在所有 JavaScript 提交中击败了16.67%的用户

```
/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function(timeSeries, duration) {
    var time=0
    for(var i=0;i<timeSeries.length;i++){
        if(Math.abs(timeSeries[i+1]-timeSeries[i])<duration){
            time+=timeSeries[i+1]-timeSeries[i]
        }else{
            time+=duration
        }
    }
    return time
};
```
