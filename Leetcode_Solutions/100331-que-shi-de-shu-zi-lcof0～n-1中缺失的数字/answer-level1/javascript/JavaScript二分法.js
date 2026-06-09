### 解题思路

排好序的确实应该优先考虑二分法

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    if (nums[0] !== 0) return 0
    let left = 0, right = nums.length, mid = 0
    while (left < right) {
        mid = Math.floor((left + right) / 2)
        if (nums[mid] === mid) {
            left = mid + 1
        } else {
            right = mid
        }
    }
    return left
};
```