双指针

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let left = 0, right = nums.length - 1;
    let ans = [];
    while( left <= right) {
        if (nums[left] + nums[right] === target) {
            return [nums[left], nums[right]];
        } else if (nums[left] + nums[right] < target) {
            ++left;
        } else {
            --right;
        }
    }
};
```