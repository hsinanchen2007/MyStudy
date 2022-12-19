### 代码
```javascript
var matrixReshape = function(nums, r, c) {
    const arr = flattenDeep(nums)
    console.log(arr)
    if (arr.length !== r * c) {
        return nums
    }
    let k = 0
    const res = []
    for (let i = 0; i < r; i++) {
        res.push(new Array(c).fill(null))
    }
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            res[i][j] = arr[k]
            k++
        }
    }
    return res
};
function flattenDeep(arr){
    return arr.reduce((prev, next)=>{
        return prev.concat(Array.isArray(next) ? flattenDeep(next) : next);
    },[])
}
```
时间复杂度：O(r * c)
空间复杂度：O(r * c)