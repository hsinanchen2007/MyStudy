### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
  let index = 0
  for(;index<nums.length;index++){
      if(nums[index] !== index) {
        break;
      }
  }
  return index;
};
```