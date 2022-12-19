```js
const findLongestWord = (s, d) => {
  // 按字典序排列
  d = d.sort()
  console.log(d)
  let maxLength = 0
  let maxWord = ''
  // 查找关键字是否按顺序散布在s中
  const includes = (arr, keyword) => {
    let start = 0
    for (const s of keyword) {
      start = arr.indexOf(s, start)
      if (start < 0) {
        return false
      } else {
        start++
      }
    }
    return true
  }
  for (const keyword of d) {
    if (includes(s, keyword) && keyword.length > maxLength) {
      maxLength = keyword.length
      maxWord = keyword
    }
  }
  return maxWord
}
```
