### 解题思路
详情，看代码解析

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
   let i = 0
  let len = nums.length
  if(len == 0) return  false // 题目要求需要判断空数组的情况
  while (i <= len) { // 循环数组
    if (nums.indexOf(nums[i]) == nums.lastIndexOf(nums[i])) {
      i = i + 1 // 当前元素没有重复，继续往后遍历，查找
    } else {
      return true // 如果相等了，返回
    }  
  }
  return false // 遍历完数组所有元素，没有找到相等的，返回
};
```