思路：因为限定 O(log n)，所以使用二分法
1. 数组分为两组，那么必定有一组是有序的，判断是否在这个有序的区间内；
2. 如果在这个区间，继续二分法直到找到这个值；
3. 如果不在这个区间，则将另一个区间继续这样寻找；
4. 注意：由于是向下取整，最好先判断右侧是否为有序数组。

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
  let len = nums.length;
  if (len === 0) return -1;

  return handler(0, len - 1, nums, target);
};

function handler(l, r, nums, target) {
  if (l > r) return -1;
  let mid = (l + r) / 2 | 0;
  if (nums[mid] === target) return mid;
  if (nums[r] > nums[mid]) {
    if (nums[r] >= target && nums[mid] < target)
      return handler(mid + 1, r, nums, target);
    return handler(l, mid - 1, nums, target);
  } else {
    if (nums[l] <= target && nums[mid] > target)
      return handler(l, mid - 1, nums, target);
    return handler(mid + 1, r, nums, target)
  }
}
```