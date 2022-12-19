### 解题思路

因为大于一半, 所以排序后的 中间那个数必是

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
  nums.sort((a,b) => a - b)
  return nums[Math.floor(nums.length / 2) ]
};
```