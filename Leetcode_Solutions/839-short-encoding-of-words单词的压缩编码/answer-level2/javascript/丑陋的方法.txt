### 解题思路
先把`words` 数组按照字符串的长度进行从大到小的排序，为了避免 `me#time#` 这样的索引字符串。
遍历数组，判断索引字符串`strs` 中是否存在与`words[i]`相同的字符串，当存在相同的字符串的时候，判断该字符串的后一位是#或者是字符串的最后一位，如果是就表示索引字符串不用添加字符，如果不是就继续判断后面字符串有没有满足上面的条件的。
最后给索引字符串加上#号结尾
输出索引字符串的长度
### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
  let strs = ''
  words.sort((val1, val2) => val1.length < val2.length)
  words.forEach(( val, index) => {
    if (index === 0) {
      strs += val
    } else {
      let copyStrs = strs
      let oldIncludesIndex = strs.indexOf(val)
      while (oldIncludesIndex > -1) {
        if (copyStrs[oldIncludesIndex + val.length] === '#' || oldIncludesIndex + val.length === copyStrs.length) {
          oldIncludesIndex = -2
        } else {
          copyStrs = copyStrs.slice(oldIncludesIndex + 1)
          oldIncludesIndex = copyStrs.indexOf(val)
        }
      }
      if (oldIncludesIndex === -1) {
        strs += '#' + val
      }
    }
  })
  strs += '#'
  return strs.length
};
```