### 解题思路
```bash
1. 转成字符串(题目希望有别的方式)
2. 数字反转 结果rv
  判断x<0肯定不是回文整数
  拿个位tmp，x % 10， rv = tmp
  拿个位tmp, rv = rv * 10 + tmp
  ...
  rv === x即反转后的和原整数相等，就可以判断出是回文了
```
### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
  var rv = 0
  var scopeX = x
  // 处理负数
  if (scopeX < 0) {
      return false
  }
  while (scopeX > 0) {
      var tmp = scopeX % 10
      rv = rv * 10 + tmp
      scopeX = parseInt(scopeX / 10)
  }
  return rv === x
};
```