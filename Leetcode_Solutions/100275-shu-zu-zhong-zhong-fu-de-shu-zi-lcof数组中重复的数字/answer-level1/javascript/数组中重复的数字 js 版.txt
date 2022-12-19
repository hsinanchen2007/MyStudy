### 解题思路
将数组中重复的数字删除，再与原数组逐个比较，第一个不一样的数字就说明是第一个重复的数字。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
  let arr = Array.from(new Set(nums));
  let num;
  for (let i=0; i<nums.length; i++) {
    if (arr[i] !== nums[i]) return num = nums[i];
  }
  return num;
};
```