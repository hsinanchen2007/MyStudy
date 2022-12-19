```
/**
 * @param {number[]} nums
 * @return {number}
 * 
 * 思路： 题目可以理解为，这个子数组的第一个元素前面，以及最后一个元素后面的元素都是正确升序的。
 *       所以这里通过两个循环找子数组的起点跟终点，即可得到最短长度。
 */
var findUnsortedSubarray = function(nums) {
    let p2 = 0
    let p1 = 0
    let max = nums[0]
    let min = nums[nums.length - 1]
    for (let i = 0; i < nums.length; i++) {
        max = Math.max(max, nums[i])
        if (nums[i] < max) {
            p1 = i
        }
    }
    for (let i = nums.length - 1; i >= 0; i--) {
        min = Math.min(min, nums[i])
        if (nums[i] > min) {
            p2 = i
        }
    }
    const diff = p1 - p2
    return diff > 0 ? diff + 1 : diff
};
```