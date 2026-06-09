### 解题思路

大家好，我是 17。

根据题意，数组元素全是正整数，也就是说，只要加上一个元素和必定增加，减小一个元素和必定减小，所以可以用滑动窗口法。

因为只有一层循环，所以很方便看出 时间复杂度 O(n)

### 代码

```javascript
/**
 * @param {number} s
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function (s, nums) {
  let sum = nums[nums.length - 1]
  let i = nums.length - 1; j = nums.length - 1
  let len = Infinity
  while (j >= 0) {
    if (sum >= s) {
      len = Math.min(len, i - j + 1)
      sum -= nums[i--]
    }
    else {
      sum += nums[--j]
    }
  }

  return len===Infinity?0:len
};
```