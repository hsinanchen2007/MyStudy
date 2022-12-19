环形使得第一和最后一个不能在同一次动态规划中。相当于进行两次198的打家劫舍的计算，比较出最大的一个
```
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    let len = nums.length
    if(len === 0) return 0
    else if(len === 1) return nums[0]
    return Math.max(getRob(nums, 0, len-1), getRob(nums, 1, len))
};

var getRob = function(nums, start, end){
    let dp0 = 0, dp1 = nums[start]
    for(let i = start+1; i < end; i++){
        let tdp0 = Math.max(dp0, dp1),
            tdp1 = dp0 + nums[i]
        dp0 = tdp0
        dp1 = tdp1
    }
    return Math.max(dp0, dp1)
}
```
