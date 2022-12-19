```
/**
 * 方法一：顺序遍历
 * 时间复杂度O(n)
 * 空间复杂度O(1)
 * @param {string} S
 * @return {number[][]}
 */
var largeGroupPositions = function(S) {
  const n = S.length
  let res = []
  let count = 1 // 计数
  let start // 记录分组开始位置
  let end // 记录分组结束位置
  for (let i = 1; i < n; i++) {
    if (S[i] === S[i - 1]) {
      count++
      if (start === undefined) {
        start = i - 1
      }
    }

    if (S[i] !== S[i - 1]) {
      if (count >= 3) {
        end = i - 1
        res.push([start, end])
      }
      // 重置开始、结束和计数
      start = undefined
      end = undefined
      count = 1
    }
  }

  // 处理特殊情况：整个字符串都是相同的字符或结尾的字符串都是相同字符
  if (end === undefined && count >= 3) {
    res.push([start, n - 1])
  }
  return res
};
```
