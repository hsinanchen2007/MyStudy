### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
  let start = nums.indexOf(target)
  let end = nums.lastIndexOf(target)
  return [start,end]
};
```