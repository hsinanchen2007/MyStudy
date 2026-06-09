### 解题思路

大家好，我是17

这题就是有环加无环两种情况分别处理，取最大的。

无环的 getMax 方法 取一下就好。

有环的，这个思维有点跳跃。算有环，需要先求出连续子数组的最小值，用总和减连续子数组的最小值，那不就是连续子数组的最大值了吗。

连续子数组的最小值，需要把数组中的数据取反，算出连续最大，得出结果再取反，得到连续最小。

需要注意的一点，如果数组全是负数，连续子数组的最小值就是所有的数，那么算最大值的时候就一个数也没有了，不符合题意，需要排除。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var maxSubarraySumCircular = function (A) {
  let sumA = A.reduce((sum, n) => sum + n, 0)
  let maxNoCircle = getMax(A)

  A = A.map(item => -item)
  let maxHasCircle = sumA + getMax(A)
  if (maxHasCircle === 0) {
    return maxNoCircle
  }
  else {
    return Math.max(maxHasCircle, maxNoCircle)
  }

  //有更快更省内存的写法
  function getMax(A) {
    let dp = [A[0]]
    for (let i = 1; i < A.length; i++) {
      dp[i] = Math.max(dp[i - 1] + A[i], A[i])
    }
    return Math.max(...dp)
  }
};
```