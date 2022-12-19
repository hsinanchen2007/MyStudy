> 思路：
> 字典序：从右往左，找到第一个左值小于右值的数，然后从右往左，找到第一个大于该左值的数，交换这两个值，并将该左值(不包含)右边的进行从小到大进行排序(原来为降序，只需要改为升序)。

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
  let len = nums.length;
  if (len <= 1) return;

  for (let i = len - 2; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      for (let j = len - 1; j > i; j--) {
        if (nums[i] < nums[j]) {
          swap(i, j, nums)
          break;
        }
      }
      let x = i + 1, y = len - 1;
      while (x < y) swap(x++, y--, nums)
      break;
    }
    if (i === 0) {
      let x = i, y = len - 1;
      while (x < y) swap(x++, y--, nums)
    }
  }
};

function swap(i, j, nums) {
  let t = nums[i];
  nums[i] = nums[j];
  nums[j] = t;
}
```