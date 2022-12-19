### 解题思路

大家好，我是 17

先排序

1. 先确认第一个数
2. 用双指针法找出第二，第三个数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
  nums.sort((a, b) => a - b)
  let one = null
  let lastOne = null
  let result = Infinity
  for (let i = 0; i < nums.length - 2; i++) {
    one = nums[i]
    if (one === lastOne) continue
    lastOne = one
    let m = i + 1, n = nums.length - 1

    while (m < n) {
      let sum = one + nums[m] + nums[n]
      if (sum === target) return target


      if (Math.abs(result - target) > Math.abs(sum - target)) {
        result = sum
      }
      if (sum > target) n--
      else m++
    }

  }
  return result

};
```