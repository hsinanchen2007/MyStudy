### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function (nums, k) {
  if (k < 0) {
    return 0;
  }
  let pos = new Map();
  let len = nums.length;
  let count = 0;

  for (let i = 0; i < len; i++) {
    if (pos.has(nums[i])) {
      pos.set(nums[i], pos.get(nums[i]) + 1);
    } else {
      pos.set(nums[i], 1)
    }
  }

  for (let i = 0; i < len; i++) {
    if (pos.has(nums[i]) && pos.get(nums[i]) > 0) {
      if ((k > 0 && pos.has(nums[i] + k)) || (k === 0 && pos.get(nums[i]) > 1))
        count++;
      pos.set(nums[i], -1);
    }
  }
  return count;
};
```
1. 集合是整数集，存在小于0的元素，无法用数组来存储集合的分布情况，可以使用`Map`存储
2. 题意中两个整数的差值不可能为负数,`k<0`的情况返回结果为 `0`
3. 对于集合中的数字`a`,只判断`a+k`是否在集合中,不判断`a-k`是否在集合中,简化逻辑
4. 对已经判断过的数字标记，减少重复判断