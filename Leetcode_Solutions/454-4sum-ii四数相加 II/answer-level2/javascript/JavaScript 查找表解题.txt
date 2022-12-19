### Analyze

解题思路: 如果正常暴力解法为 n^4, n^3 在 0 <= N <= 500 的数量级下已经达到 `125000000`, 根据[算法复杂度](https://github.com/MuYunyun/blog/blob/master/BasicSkill/algorithm/算法复杂度.md) 里对数量与时间的统计, 算法的数据复杂度理应不超过 n^2。

因此我们将 C 与 D 和出现的次数存进查找表中, 从而优化算法复杂度(查找表的关键是确认存进查找表的 key 和 value 是多少)。

```js
/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
var fourSumCount = function(A, B, C, D) {
  const tmpMap = new Map()
  for (let ic = 0; ic < C.length; ic++) {
    for (let id = 0; id < D.length; id++) {
      const sumC_D = C[ic] + D[id]
      const hasSumC_D = tmpMap.has(sumC_D)
      if (hasSumC_D) {
        tmpMap.set(sumC_D, tmpMap.get(sumC_D) + 1)
      } else {
        tmpMap.set(sumC_D, 1)
      }
    }
  }

  let count = 0

  for (let ia = 0; ia < A.length; ia++) {
    for (let ib = 0; ib < B.length; ib++) {
      const sumA_B = A[ia] + B[ib]
      tmpMap.has(-sumA_B) && (count = count + tmpMap.get(-sumA_B))
    }
  }

  return count
}
```

![](https://pic.leetcode-cn.com/a8dbe300499ac79a591e80a6775988bd621dcb6979b6a0ff366cadd62b9b4187.jpg)

### Sister Title

18(题目相似, 但是因为传入参数不同导致解法不同)

> 为确保内容的实时、准确性, 可以[查看原文](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)