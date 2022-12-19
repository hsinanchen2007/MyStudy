```
// 官方思路改为正常代码，立刻通俗易懂
var minKBitFlips = function(A, K) {
  // 用 flip 表示当前翻转状态，负负得正，所以用布尔值即可
  let flip = false
  // count 用于记录翻转次数
  let count = 0
  // 见下方具体使用处
  let flipOneMore = Array(A.length + 1).fill(false)
  
  for (let [i, e] of A.entries()) {
    // 判断当前位置是否需要额外补一次翻转
    if (flipOneMore[i]) flip = !flip
    // 未翻转找零，翻转找 1，所以直接判等即可
    if (+flip == e) {
      if (i + K > A.length) return -1
      flip = !flip
      // 如果 i 处发生翻转
      // 则行进到 i + K 处应该额外补一次翻转
      flipOneMore[i + K] = true
      count++
    }
  }
  return count
};
```
