### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
const findMaxConsecutiveOnes = function(nums) {
  let max = 0;
  let current = 0;
  for (const item of nums) {
    if (item == 1) {
      current++;
      max = Math.max(max, current);
    } else {
      current = 0;
    }
  }
  return max;
};
```