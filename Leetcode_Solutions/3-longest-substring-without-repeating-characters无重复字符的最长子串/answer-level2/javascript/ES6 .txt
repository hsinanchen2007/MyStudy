### 解题思路
maxStr：记录最大字符串
max：记录最大值

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  if (!s) {
    return 0
  }

  let max = 0
  let maxStr = ''
  let index = -1;
  for (const char of s) {
    index = maxStr.indexOf(char)
    if (index !== -1) {
      index++
      maxStr = maxStr.substr(index)
    }
    maxStr += char
    let len = maxStr.length
    max = max < len ? len : max
  }
  return max
};
```