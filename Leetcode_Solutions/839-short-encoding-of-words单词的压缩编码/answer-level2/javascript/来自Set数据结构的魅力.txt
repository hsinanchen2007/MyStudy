![image.png](https://pic.leetcode-cn.com/d9b726a5d3f6479642f56bb8c5240f1ddc525e350e3dd4f188fea69e988404be-image.png)

### 解题思路
每个单词, 删除在Set中其不包含自身的从尾部开始的子串

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
  const wordsSet = new Set(words)
  for (let word of wordsSet) {
    for (let i = word.length - 1; i > 0; --i) {
      const str = word.substring(i)
      if (wordsSet.has(str)) {
        wordsSet.delete(str)
      }
    }
  }
  let res = 0
  wordsSet.forEach(word => {
    res += word.length + 1
  })
  return res
};
```