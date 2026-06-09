### 解题思路
思路很简单，遇到不同的数字则填写到慢指针处，慢指针+1
最后返回慢指针即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  if (nums.length === 0) {
    return 0;
  }
  let slow = 1;
  let pre = nums[0];
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] !== pre) {
      nums[slow++] = nums[i];
      pre = nums[i];
    }
  }
  return slow;
};
```