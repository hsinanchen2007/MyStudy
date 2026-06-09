
大家好，我是 17

## 方法一，暴力优化

暴力这个名称一般不大爱听，不过，这道题的这个方法，速度还是很快的，而且容易想到，也不容易写错。

**解题思路** 先暴力找第一个，第二个数，通过  set 找第三个数。

### 代码
```
/**
 * @param {number[]} A
 * @return {number}
 */
var lenLongestFibSubseq = function (A) {
  let set = new Set(A)
  let count = 2
  let max = 0
  
  for (let firstIndex = 0; firstIndex < A.length - 2; firstIndex++) {
    for (let secondIndex = firstIndex + 1; secondIndex < A.length - 1; secondIndex++) {
      count = 2
      let f1 = A[firstIndex]
      let f2 = A[secondIndex]
      let f3 = f1 + f2
      while (set.has(f3)) {
        //console.log(f1, f2, f3)
        count++
        if (count > max) max = count
        f1 = f2
        f2 = f3
        f3 = f1 + f2
      }
    }
  }
  return max
};
```
## 方法二，动态规划

动态规划这个词听起来高大尚，不过，动态转移方程不大好想。这个只能靠多经多见。见得多了，新题目才可能想出方案，因为思想都是相通的。 想从来没见过自己想出来？好吧，如果你时间无限多，也可以一试。我多说这个的原因是大家都是普通人，能力 90% 都是靠学习和积累得来的，如果自己独立没想出解法，也很正常，不要恢心。

**解题思路**  转移方程 `dp[i][j]=dp[k][i]+1`

以索引 i , j 结尾的最大长度可以由 k , i 结尾 +1 获得，其中` k <i` 且 `A[k]+A[i]=A[j]`

如何找到 k ？需要一个 map 先把值和索引的对应关系记录下来，这样就可以  O(1) 的时间拿到值 

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var lenLongestFibSubseq = function (A) {
  let map = new Map()
  for (let i = 0; i < A.length; i++) {
    map.set(A[i], i)
  }
  let max = 0
  let dp = Array.from({ length: A.length }, () => new Array(A.length).fill(2))
  for (let secondIndex = 0; secondIndex < A.length - 1; secondIndex++) {
    for (let thirdIndex = secondIndex + 1; thirdIndex < A.length; thirdIndex++) {
      let f2 = A[secondIndex]
      let f3 = A[thirdIndex]
      let f1 = f3 - f2
      if (f1 < f2 && map.has(f1)) {
        
        dp[secondIndex][thirdIndex] = Math.max(dp[map.get(f1)][secondIndex] + 1, dp[secondIndex][thirdIndex])
        max = Math.max(max, dp[secondIndex][thirdIndex])
      }
    }
  }
  return max
};
```
