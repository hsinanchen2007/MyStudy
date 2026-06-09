
```javascript
var search = function(nums, target) {
  if (nums.length === 0) return -1

  function bSearch(nums, i, j, target) {
    if (i > j) return -1
    const mid = ~~((i + j) / 2)
    if (nums[mid] === target) return mid
    
    return shouldSearchInLeft()
      ? bSearch(nums, i, mid - 1, target)
      : bSearch(nums, mid + 1, j, target)
    
    function shouldSearchInLeft () {
      return (nums[i] <= nums[j])
        // 给定范围序列完全有序时，退化为普通的二分搜索
        ? nums[mid] >= target
        // 非完全有序时的分割条件
        : (nums[i] <= nums[mid] && target >= nums[i] && target <= nums[mid]) ||
          (nums[i] > nums[mid] && (target < nums[mid + 1] || target > nums[j]))
    }
  }

  return bSearch(nums, 0, nums.length - 1, target)
};
```
