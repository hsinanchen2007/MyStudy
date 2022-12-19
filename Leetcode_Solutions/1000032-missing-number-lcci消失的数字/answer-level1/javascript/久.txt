### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
  let max = Math.max(...nums)
  nums.sort((a,b) => a -b)
  for(let i = 0; i <= max; i++){
    if(nums[i] !== i) return i
  }
  return max + 1
};
```