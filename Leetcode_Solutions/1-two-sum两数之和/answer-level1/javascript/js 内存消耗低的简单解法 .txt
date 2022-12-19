### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  for (let i = 0; i < nums.length; i++) {
    let j = nums.indexOf(target - nums[i],i+1)
    if(j !== -1) {
      return [i,j]
    } 
  }
};
```
时间换了内存，这道题应该最好的应该是哈希的写法

思路:
  遍历一遍，寻找当前元素+ x = 目标值 中 x 的值  
  >  nums.indexOf(target - nums[i],i+1)
  记得不要从当前位置找






