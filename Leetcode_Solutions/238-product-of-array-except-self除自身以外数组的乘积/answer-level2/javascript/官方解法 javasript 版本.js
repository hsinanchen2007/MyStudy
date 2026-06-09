### 解题思路

大家好，我是 17

思路就是官方出的那个。

1.记录每个元素左面所有元素的乘积（不包括自身）
2.右边的乘积不需要记录，直接和左面乘积相乘

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  let v = 1
  let result=[1]
  for (let i = 1; i < nums.length; i++) {
    v *= nums[i - 1]
    result[i] = v
  }
   v = 1
  for (let i = nums.length - 1; i > 0; i--) {
    v *= nums[i]
    result[i - 1] *= v
  }
  return result
};
```