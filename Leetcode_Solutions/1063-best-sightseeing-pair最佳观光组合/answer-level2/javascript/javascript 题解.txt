### 解题思路

大家好，我是 17

这道题的关键在于转换思路。 `（A[i] + A[j] + i - j）`看成 `（A[i] + i, A[j] - j）`

暴力法也是可以通过的，但时间复杂度是 O(n2) 

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var maxScoreSightseeingPair = function (A) {
  let max = 0
  let maxAI = A[0]
  for (let i = 1; i < A.length; i++) {
    let AJ = A[i] - i
    max = Math.max(AJ + maxAI, max)
    maxAI = Math.max(maxAI, A[i] + i)
  }
  return max
};
```