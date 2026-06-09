### 解题思路

大家好，我是 17

没什么说的，就是官方解法的javascript 版本。

总结一下，就是这种有限的，象是 26个字母，或 100左右量级的有限数，可以考虑装桶。

### 代码

```javascript
/**
 * @param {number[]} ages
 * @return {number}
 */
var numFriendRequests = function (ages) {
  let ageList = new Array(121).fill(0)
  for (let age of ages) {
    ageList[age]++
  }
  let count = 0
  for (let i = 1; i < ageList.length; i++) {
    let couintA = ageList[i]
    for (let j = 1; j <= i; j++) {
      if (j <= 0.5 * i + 7) continue
      if (j > 100 && i < 100) continue
      let countB = ageList[j]
      count += countB * couintA
      if (i == j) count -= couintA
    }
  }
  return count
};
```