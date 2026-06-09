
- 思路
    -   假设第一个字符串为最长公共前缀 reg 。
        -   如果第一个字符串 reg 不存在，就取空字符串 '' 
        -   长度为0，返回 "" 
    -    对数组进行遍历，判断字符串是否以 reg 
        -   如果是，返回 reg 
        -   如果不是， reg 减去最后一位字符串，再次遍历匹配   

```js
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
  let reg = strs[0] || ''
  if (reg.length === 0) { return '' }
  for(let i in strs) {
      // 每一个字符串为strs[i]
    while(strs[i].indexOf(reg) !== 0) { 
        reg = reg.substring(0, reg.length - 1) 
    }
  }
  return reg
};
```