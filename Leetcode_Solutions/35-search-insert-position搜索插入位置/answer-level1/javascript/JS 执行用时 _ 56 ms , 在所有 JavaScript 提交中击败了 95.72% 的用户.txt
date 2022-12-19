### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    if (nums && Array.isArray(nums)) {
        let len = nums.length
        if (!len) return 0
        if (nums[0] >= target) return 0
        if (nums[len - 1] < target) return len
        let left = 1
        let right = len - 1
        while(left <= right) {
            let mid = Math.floor(left + (right - left) / 2)
            if (nums[mid] === target) {
                return mid
            }
            if (nums[mid] > target) {
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        return left
    }
};
```