```js
var lengthOfLongestSubstring = function(s) {
  let max = 0
  let list = []

  for (let i = 0; i < s.length; i++) {
    const letter = s[i]
    const repeatIndex = list.indexOf(letter)
    list.push(letter)
    // 如果重复，去掉前半部分，剩下的是不重复的
    if (repeatIndex !== -1) {
      list = list.slice(repeatIndex + 1)
      // 肯定没之前的长
      continue
    }
    // 比较当前长度和最高纪录
    max = Math.max(max, list.length)
  }
  return max
}
```