### 解题思路
双周赛22 第一题
范围不大 暴力遍历就行 O(n^2)
### 代码

```javascript
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @param {number} d
 * @return {number}
 */
var findTheDistanceValue = function (arr1, arr2, d) {
  let ans = 0
  arr1.forEach(ele => {
    let flag = true
    arr2.forEach(item => {
      if (Math.abs(ele - item) <= d) flag = false
    })
    flag && ans++
  })
  return ans
}
```