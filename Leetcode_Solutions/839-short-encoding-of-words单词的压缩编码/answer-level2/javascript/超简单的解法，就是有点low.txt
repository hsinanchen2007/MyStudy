### 解题思路
此处撰写解题思路

### 代码

```javascript
var minimumLengthEncoding = function(words) {
  words = words.sort((a, b) => b.length - a.length)
  let word = ''
  words.forEach(val => {
    if (!~word.indexOf(val + '#')) {
      word += val + '#'
    } 
  })
  return word.length
};

```