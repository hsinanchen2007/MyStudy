

```javascript []
var compress = function(chars) {
  var count = 1//字母计数
  for (let i = 0; i < chars.length; i++) {
    if (chars[i] === chars[i + 1]) {
      count++
      chars.splice(i, 1)//删除重复字母
      i--
    } else if (count !== 1) {
      let str = count.toString(10)
      chars.splice(i + 1, 0, ...count.toString(10).split(''))//添加字母长度
      i += str.length
      count = 1
    }
  }
  return chars.length
}
```