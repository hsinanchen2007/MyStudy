因为题目明确了输出结果中的每个元素一定是`唯一的`, 因而可以使用集合 Set 唯一的特性, 完成题解。

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
  const resultSet = new Set()
  const num1Set = new Set(nums1)
  for (let i = 0; i < nums2.length; i++) {
    if (num1Set.has(nums2[i])) {
      resultSet.add(nums2[i])
    }
  }

  return [...resultSet]
}
```

> [JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)