### 解题思路
可以先将 chars 字符的出现次数单独存为 charTable，存的结构**可以是 object 也可以是 array**，但要注意，**object 的开销比 array 要大**。
之后遍历 words 元素的每一个字符，检查字符是否在 charTable 中，以及是否用尽 charTable 中的次数。

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
  const charList = chars.split('')
  const charTable = charList.reduce((list, letter) => {
    const code = letter.charCodeAt() - 97
    list[code] ? (list[code]++) : (list[code] = 1)
    return list
  }, Array(26))
  let count = 0
  for (let word of words) {
    let newTable = [...charTable]
    for (let i = 0; i < word.length; i++) {
      const ch = word[i].charCodeAt() - 97
      if (newTable[ch] === undefined) {
        newTable = undefined
        break
      }
      newTable[ch]--
      if (newTable[ch] < 0) {
        newTable = undefined
        break
      }
    }
    if (newTable) {
      count += word.length
    }
  }
  return count
};
```