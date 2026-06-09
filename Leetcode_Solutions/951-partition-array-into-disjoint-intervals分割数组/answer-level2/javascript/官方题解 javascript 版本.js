### 解题思路

大家好，我是 17

一个拿空间换时间的例子。
本来如果不用辅助数组的话，对于每个 index ,都得计算 index 前面的最大值，和 index,后面的最小值，用辅助数组就只需要计算一次。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var partitionDisjoint = function (A) {

  let min = []
  let minVal = Infinity
  let max = []
  let maxVal = -Infinity
  for (let i = A.length - 1; i >= 0; i--) {
    if (A[i] < minVal) {
      minVal = A[i]
    }

    min.unshift(minVal)
  }
  for (let i = 0; i < A.length; i++) {
    if (A[i] > maxVal) {
      maxVal = A[i]
    }
    max.push(maxVal)
  }
  for (let i = 0; i < A.length - 1; i++) {
    if (max[i] <= min[i + 1]) {
      return i + 1
    }
  }

};
```