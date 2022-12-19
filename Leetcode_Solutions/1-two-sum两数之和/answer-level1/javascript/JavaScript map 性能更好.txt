### 解题思路
1. map 比较，耗时短
2. 普通双层循环，耗时久

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  let map = new Map();
  for (let i = 0; i < nums.length; i++) {
    const diff = target - nums[i];
    if (map.has(diff)) {
      return [map.get(diff), i];
      break;
    }
    map.set(nums[i], i);
   }
};
```