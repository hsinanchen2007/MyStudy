```
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    var obj = {};
    for(var i=0; i<nums.length; i++) {
        // 如果哈希表中存在 且满足绝对值条件，则返回true
        if(obj[nums[i]] !== undefined && (i - obj[nums[i]] <= k)) {
            return true;
        }
        // 否则更新 哈希表值， 因为元素升序循环
        obj[nums[i]] = i;
    }
    return false;
};
```
