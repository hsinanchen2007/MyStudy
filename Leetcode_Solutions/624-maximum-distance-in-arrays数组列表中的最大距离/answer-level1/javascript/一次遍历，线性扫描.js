### 解题思路
1、每个数组的第一个值和最后一个值才有意义
2、每次比较有四个数字：当前arrays[i]数组的最大、最小值tmpMax、tmpMin；以及 前面所有数组arrays[0至i-1]的最大值max、最小值min
3、结果res = Math.max(max-tmpMin, tmpMax-min, res) 三个值中最大的那个
### 代码

```javascript
/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function(arrays) {
    let max=-Infinity,min=+Infinity,res=0
    for(let i=0; i<arrays.length;i++){
        let tmpMin = arrays[i][0]
        let tmpMax = arrays[i][arrays[i].length-1]
        res = Math.max(max-tmpMin, tmpMax-min, res)
        max = Math.max(max, tmpMax)
        min = Math.min(min, tmpMin)
    }
    return res
};
```