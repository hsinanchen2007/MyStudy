> 思路：
> 1. 如果不存在为 0 的数，那么肯定能到达最后一个位置
> 2. 除最后一位外，如果 i 位置为 0，那么向前查找是否存在 j 位置使得 j + nums\[j\] > i
> 3. 最后一位是否为 0 不影响结果，所以不用判断

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
  let len = nums.length;
  let pos = undefined;
  for (let i = len - 2; i >= 0; i--) {
    if (nums[i] === 0 && pos === undefined)
      pos = i;
    if (pos !== undefined && i + nums[i] > pos)
      pos = undefined
  }
  return pos === undefined
};
```