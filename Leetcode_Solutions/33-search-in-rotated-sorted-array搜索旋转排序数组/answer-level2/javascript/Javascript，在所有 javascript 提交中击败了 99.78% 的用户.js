### 解题思路
分开判断

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    if (nums.length === 0) return -1
    function binarySearch(nums, start, end, tar) {
        const mid = start + ((end - start) >> 1)
        if (start === end) return nums[start] === tar ? start : -1
        else if (start > end) return -1
        else if (nums[mid] === tar) return mid
        else if (nums[mid] > nums[start] && nums[mid] > tar && tar > nums[start]) return binarySearch(nums, start, mid - 1, tar)
        else if (nums[mid] < nums[end] && nums[mid] < tar && tar < nums[end]) return binarySearch(nums, mid + 1, end, tar)
        else {
            return Math.max(binarySearch(nums, start, mid - 1, tar), binarySearch(nums, mid + 1, end, tar))
        }
    }
    return binarySearch(nums, 0, nums.length - 1, target)
};
```