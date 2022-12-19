### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
const remember = [true]
  for (let i = 1; i < nums.length; i++) {
    const start = i - nums[nums.length - 1 - i]
    remember[i] = remember
      .slice(start > 0 ? start : 0, i)
      .some((isGood) => isGood)
  }
  return nums.length === 1 ? true : remember[nums.length - 1]
};
```