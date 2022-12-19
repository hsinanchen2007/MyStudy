### 解题思路
以数组中第一个词为基准判断，使用num标记截取到的位置

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  if(!strs.length) return ''
  let num = 1
  let len1 = strs[0].length
  while (num <= len1) {
    let str = strs[0].slice(0, num)
    for (let i = 0, len = strs.length; i < len; i++) {
      if (!strs[i].startsWith(str)) {
        return num === 1 ? '' : strs[0].slice(0, num - 1)
      }
    }
    num++
  }
  return num === 1 ? '' : strs[0].slice(0, num - 1)
}
```
![image.png](https://pic.leetcode-cn.com/2f671255e483d5e64989d2e300240ffb910163990ff3e9e80a42779268b9bef9-image.png)
