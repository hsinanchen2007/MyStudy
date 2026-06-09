### 解题思路
替换字符串，省内存

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function (words, chars) {

  var all = 0
  words.forEach(word => {
    var charsCopy = Array.from(chars)
    var count = 0
    for (let i = 0; i < word.length; i++) {
      let pos = charsCopy.indexOf(word[i])
      if (pos > -1) {
        charsCopy[pos] = '%'
        count++
      } else {
        count = 0
        break
      }
    }
    all += count

  })
  return all
};
```