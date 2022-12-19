```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var isMajorityElement = function(nums, target) {
    return nums.filter(item => item === target).length > nums.length / 2
};
```
