### 解题思路
首尾补两个0, 遍历寻找0的位置,用index记录索引,作为下次查找的起点,要注意循环条件控制

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let temp = [0, ...nums, 0]
    let max = 0
    let index = 0
    while(index<temp.length-2){
      let i = temp.indexOf(0, index + 1)
      max = (i - index) >= max ? (i-index) : max;
      index = i
    }
    return max - 1
};
```