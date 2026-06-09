### Analyze

题目 [15](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/15.3Sum/README.md) 的加强版, 唯一区别是定义的指针数量增加了, 仍然需要注意`解的去重`。

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
  const result = []
  if (nums.length < 4) return result
  const sortSum = nums.sort((n1, n2) => n1 - n2)
  const length = sortSum.length
  for (let i = 0; i < length - 3; i++) {
    if (i === 0 || nums[i] > nums[i - 1]) {
      let l = i + 1
      let m = l + 1
      while (l < length - 2) {
        let r = length - 1
        if (l === i + 1 || nums[l] > nums[l - 1]) {
          while (m < length - 1 && m < r) {
            let tmpArr = []
            const sum = nums[i] + nums[l] + nums[m] + nums[r]
            if (sum === target) {
              tmpArr.push(nums[i])
              tmpArr.push(nums[l])
              tmpArr.push(nums[m])
              tmpArr.push(nums[r])
              result.push(tmpArr)
              m++
              r--
              while (nums[m] === nums[m - 1]) {
                m++
              }
              while (nums[r] === nums[r + 1]) {
                r--
              }
            } else if (sum < target) {
              m++
            } else if (sum > target) {
              r--
            }
          }
        }
        l++
        m = l + 1
      }
    }
  }
  return result
}
```

假设数组的长度为 n, 算法复杂度估计为 `(n - 3) * (等差数列求和)`

### Sister Title

15、16

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)