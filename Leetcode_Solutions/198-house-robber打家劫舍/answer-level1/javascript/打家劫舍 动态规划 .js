动态规划
f(k) = max(f(k-2) + nums[k], f(k-1))
直接上代码
```
var rob = function(nums) {
    let prevMax = 0
    let curMax = 0
    for (let num of nums) {
        let temp = curMax
        curMax = Math.max(curMax, prevMax + num)
        prevMax = temp
    }
    return curMax
};
```
