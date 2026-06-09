利用异或，若满足条件，则异或的结果的二进制形式必然全为1。

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var hasAlternatingBits = function(n) {
  var result = n ^ (n >> 1);
  var str = result.toString(2);
  for (var i = 0, len = str.length; i < len; i++) {
    if (str[i] === '0') {
      return false;
    }
  }
  return true;
};
```
