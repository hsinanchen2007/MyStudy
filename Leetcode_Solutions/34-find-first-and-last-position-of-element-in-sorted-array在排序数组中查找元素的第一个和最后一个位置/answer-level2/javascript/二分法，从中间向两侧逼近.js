参考评论 @唐炜依 大神的写法，第二次循环时添加了一个判断，不然会报错。
思路：二分法
1. 先找左边界，从右侧逼近；
2. 再找右边界，从左侧逼近，注意：在跳出循环时，会出现两种情况：1. 该值等于target，2. 该值大于target

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
  let result = [-1, -1];
  let len = nums.length;
  if (len === 0) return result;
  let l = 0, r = len - 1;
  while (l < r) {
    let mid = (l + r) / 2 | 0;
    if (target <= nums[mid]) r = mid;
    else l = mid + 1
  }
  if (nums[l] !== target) return result;
  result[0] = l;

  r = len - 1;
  while(l < r) {
    let mid = (l + r) / 2 | 0;
    if (target >= nums[mid]) l = mid + 1
    else r = mid;
  }
  if (nums[r] === target) result[1] = r
  else result[1] = r - 1
  return result;
};
```