从末尾字符开始，逐一比对是否为后缀。

```js
var longestPrefix = function(s) {
  let ans = null
  for (let i = s.length - 2; i >= 0; i--) {
    let offset = 0
    while(offset < i + 1) {
      if (s[s.length - 1 - offset] !== s[i - offset]) {
        break
      }
      offset++
    }
    if (offset === i + 1) {
      ans = s.substring(0, i + 1)
      break
    }
  }
  return ans || ''
}
```
