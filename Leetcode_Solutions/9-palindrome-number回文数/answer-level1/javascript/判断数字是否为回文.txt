### 解题思路
首先将数字转为字符串，拆分成数组并反转再拼接成字符串，与原数字直接转换的字符串对比，若完全相等则返回true，否则返回false
### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
  return x.toString() === x.toString().split('').reverse().join('');
};
```