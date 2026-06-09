```
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    var m = {}
    for (var i = 0;i < nums.length;i++) {
        if (m[nums[i]] === undefined) {
            // 组内元素第一次出现
            m[nums[i]] = true
        } else {
            // 组内元素第二次出现
            return true
        }
    }
    return false
};
```
