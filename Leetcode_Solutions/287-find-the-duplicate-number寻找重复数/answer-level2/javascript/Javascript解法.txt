### 解题思路
元素范围是1~n ---减1----> 0~n-1 --->对应着索引
遍历一次,每次把当前元素-1为索引,把目标元素变成负数,当遇到目标元素已为负数时,则表示已出现过一次了,直接返回
时间复杂度O(n)
空间复杂度O(1)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
  for(let i=0;i<nums.length;i++){
    let absVal = Math.abs(nums[i])
    if(nums[absVal - 1] < 0){
      return absVal
    } else {
      nums[absVal - 1] = -nums[absVal - 1]
    }
  }
};
```