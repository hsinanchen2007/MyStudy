1、找重复，修改原数组，如果某个数未出现过，那么相应位置num[num[i] -1]置为负数，找到为num[num[i] -1] < 0 的num[i]即为重复值。
2、找缺失，nums里大于0的元素index + 1即为缺失值。

49/49 cases passed (60 ms)
Your runtime beats 100 % of javascript submissions
Your memory usage beats 80 % of javascript submissions (36.9 MB)
```
var findErrorNums = function(nums) {
    var res = []
    for (let i = 0; i < nums.length; i++) {
        var absN = Math.abs(nums[i]) - 1
        if (nums[absN] < 0) res.push(Math.abs(nums[i]))
        else nums[absN] = - nums[absN]
    }
    var s
    nums.forEach((i,idx) => s = i > 0 ? (idx + 1) : s)
    return res.concat(s)
};
```
