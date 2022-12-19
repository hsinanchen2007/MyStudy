### 解题思路
总体还是二分的思想
1. 二分获取中间值，如果中间值为target，则找到对应的index
2. 如果中间值小于`nums[end]`，则证明后半段有序，如果target在这个后半段区间（mid, end]，则寻找这个区间；否则找前半段区间；
3. 否则，前半段区间[start, mid]有序，如果target是否在这个区间，则在这个区间找；否则找后半段区间

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
 if (!nums || nums.length === 0) {
    return -1;
  }
  let index = -1;
  let start = 0;
  let end = nums.length - 1;
  while (start <= end) {
    let mid = Math.floor(start + (end - start) / 2);
    if (nums[mid] === target) {
      index = mid;
      break;
    }
    if (nums[mid] < nums[end]) {
      if (target <= nums[end] && target >= nums[mid]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    } else {
        if (target >= nums[start] && target <= nums[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
  }
  
  return index;
};
```