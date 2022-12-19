### 解题思路
二分查找 找到了之后向两边扩散 左右两点的差值
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    if(nums.length === 1) return target === nums[0] ? 1 : 0
    let left = 0
    let right = nums.length - 1
    while (left <= right) {
        let mid = Math.floor((left + right) / 2)
        if (nums[mid] == target) {
            left = mid
            right = mid
            while (nums[left - 1] == target || nums[right + 1] == target) {
                if(nums[left - 1] == target) left--
                if(nums[right + 1] == target) right++
            }
            return right - left + 1
        }
        if (nums[mid] > target) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    return 0
};
```