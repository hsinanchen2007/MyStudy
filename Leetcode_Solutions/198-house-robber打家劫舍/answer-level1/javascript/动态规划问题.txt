```
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    const len = nums.length
    if (len === 0) {
        return 0
    }
    if (len === 1) {
        return nums[0]
    }
    if (len === 2) {
        return Math.max(nums[0], nums[1])
    }
    const res = [nums[0], Math.max(nums[0], nums[1])]
    let max = Math.max(nums[0], nums[1])
    for (let i = 2; i < len; i++) {
        // 从第i + 1个房子往前偷，这个房子可以选择偷，或者不偷（也就是从第i 个房子往前偷的价值）
        res[i] = Math.max(nums[i] + res[i - 2], res[i - 1])
        max = Math.max(max, res[i])
    }
    return max
};
```
