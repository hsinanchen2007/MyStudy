```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    if(!nums) {
        return null;
    }
    for(let i = 0, len = nums.length; i < len; i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    return nums.length;
};
```
