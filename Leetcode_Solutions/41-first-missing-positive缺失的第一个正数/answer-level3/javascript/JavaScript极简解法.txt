将元素取负的目的无非是想要在原有的元素上多存储额外的信息，之所以会有很多边界情况是因为所给的数组里可能有0和负数这些干扰项。

考虑到JS中的数组可以为任意类型，所以其实有一些取巧的方法，比如不是取负，而是将其转化为字符串？

代码如下：

```javascript
var firstMissingPositive = function(nums) {
  for (const num of nums)
    if (typeof nums[+num - 1] !== 'undefined')
      nums[+num - 1] = '' + nums[+num - 1]
  for (let i = 0; i < nums.length; i++)
    if (typeof nums[i] === 'number')
      return i + 1
  return nums.length + 1
};
```
> 执行用时 :72 ms, 在所有 JavaScript 提交中击败了96.54%的用户
> 内存消耗 :34.1 MB, 在所有 JavaScript 提交中击败了68.90%的用户

