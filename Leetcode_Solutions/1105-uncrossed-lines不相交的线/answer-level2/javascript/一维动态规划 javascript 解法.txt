### 解题思路

大家好，我是 17

可以用 动态规划求解。

可以用二维动态规划 ，也可以用一维动态规划。

我第一个念头想到的是一维动态规划，A 到 B 的连线问题可以转化为 非连续上升子序列问题。

1. 把 A 可以连到 B 的所有直线（不管是不是相交）的 B 的索引记在一个数组 arr 里 。
2. 在 arr 中找 索引的最大上升子序列。

因为 A 是按升续向 B 连线，在 B 中也是找上升续列，所以 A,B的连结不会相交。但有一个例外，就是 A 中的某个点，可能和 B 中的多个点相连，因为 B 中的数并不是唯一的。 

`[1] [1,1,1,1]`  会得出 可以连四条线的结论。连在一点的也算相交，所以不对。为了避免这个问题。可以把 B 的到 A 同一点的索引值按降续排。这样按升续求解的时候自然 就排除了。代码  `map.get(n).unshift(i)` 中的 `unshift` 起到了按降序排的作用

最后，一维数组有一个优点，省内存，现在的代码已经是内存打败 100%，还可以再优化。

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var maxUncrossedLines = function (A, B) {
  let map = new Map()
  for (let i = 0; i < B.length; i++) {
    let n = B[i]
    if (map.has(n)) {
      map.get(n).unshift(i)
    }
    else {
      map.set(n, [i])
    }
  }
  let arr = []
  for (let i = 0; i < A.length; i++) {
    let n = A[i]
    if (map.has(n)) {
      arr = arr.concat(map.get(n))
    }
  }
  let dp = new Array(arr.length).fill(1)
  for (let i = 1; i < arr.length; i++) {
    for (let j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        dp[i] = Math.max(dp[i], dp[j] + 1)
      }
    }
  }
  return dp.length ? Math.max(...dp) : 0

};
```