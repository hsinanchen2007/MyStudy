### 解题思路
此处撰写解题思路
 1.先将chars以map的形式存储起来，将字母作为键值，个数为value值，方便后续减去
 2.循环words数组，将每个单词进行循环对比，成功的返回true，将数字累计

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
  const arr = new Map()
  for (const i of chars) {
    arr.set(i, arr.has(i) ? arr.get(i) + 1 : 1)
  }
  let count = 0
  for (const k of words) {
    if (check(k, new Map(arr))) {
      count += k.length
    }
  }
  return count
}

function check(k, arr) {
  for (const s of k) {
    if (arr.has(s) && arr.get(s) > 0) {
      arr.set(s, arr.get(s) - 1)
    } else {
      return false
    }
  }
  return true
}
```