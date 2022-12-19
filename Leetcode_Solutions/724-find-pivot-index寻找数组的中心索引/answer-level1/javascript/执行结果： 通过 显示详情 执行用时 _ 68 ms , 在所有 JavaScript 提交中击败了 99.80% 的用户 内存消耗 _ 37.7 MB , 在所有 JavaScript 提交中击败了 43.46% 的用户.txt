```
/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function (nums) {
    let res = -1;
    if (nums.length === 0) return res
    let sum = nums.reduce((pre, cur) => {
        return pre + cur
    })
    let left = 0

    for (let i = 0; i < nums.length; i++) {
        if (left === sum - nums[i] - left) {
            return res = i
        }
        left += nums[i]
    }

    return res
};
```
