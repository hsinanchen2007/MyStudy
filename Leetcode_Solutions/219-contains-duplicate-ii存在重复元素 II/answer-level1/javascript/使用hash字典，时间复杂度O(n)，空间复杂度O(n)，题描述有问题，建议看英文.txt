```
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    var m = {}
    for (var i = 0;i < nums.length;i++) {
        if (m[nums[i]] === undefined) {
            m[nums[i]] = i
        } else {
            // i 一定比 m[nums[i]] 大
            // 满足条件
            if (i - m[nums[i]] <= k) {
                return true
            } else {
                // 不满足条件 更新 m[nums[i]]
                m[nums[i]] = i
            }
        }
    }
    return false
};
```
