### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  if (!strs.length || !strs[0]) {
    return ''
  }
  if (strs.length === 1) {
    return strs[0]
  }

  let prefix = strs[0]
  let result = ''
  let continueRun = true


  for (let index = 0; index < prefix.length; index++) {
    let char = prefix[index];
    let i = 1
    while (i < strs.length) {
      if (strs[i][index] !== char) {
        continueRun = false
        break
      }
      i++
    }
    if (!continueRun) {
      result = prefix.substring(0, index)
      break;
    }
  }

  return continueRun ? prefix : result
};
```