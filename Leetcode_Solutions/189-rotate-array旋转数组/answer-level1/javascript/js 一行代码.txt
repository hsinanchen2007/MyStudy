### 解题思路
1. 从末尾取值
2. 利用...和unshift拆并入数组

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
  nums.unshift(...nums.splice(nums.length - k, k));
  return nums
};

```