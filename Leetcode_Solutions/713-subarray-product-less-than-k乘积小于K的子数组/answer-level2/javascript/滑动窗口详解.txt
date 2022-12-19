### 解题思路

大家好，我是 17

因为都是正整数，乘一个数或除一个数乘积保证单调变化，所以可以用窗口法

还有一个关键约束条件：连续子数组。所以在窗口中加一个数的时候，增加的连续子数组数为 `j-i+1`

比如 目前的数组是 `[1,2,3]`,准备把 4 加到窗口中，从后往前看可以组成的 “连续” 子数组为 `[4,3]`,`[4,3,2]`,
`[4,3,2,1]`，也就是说原来数组中有几个数，新增加一个数，就会增加几个连续子数组。

在窗口中，如果整体乘积大于 `k` ，除掉窗口中的第一个数，如果小于，向前移动


### 代码

```javascript

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function (nums, k) {
  let mul = 1
  let count = 0
  for (let i = 0, j = 0; i < nums.length && j < nums.length;) {
    let tmp = mul * nums[j]
    if (tmp < k) {
      mul = tmp
      count += j - i + 1
      j++
    }
    else {
      mul /= nums[i]
      i++
    }
  }
  return count
};
```