### 解题思路
此处思路是正负取反，来判断回文数。

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
  let abc = [...String(x)];
  if((x > 0 ? 1: -1) * abc.reverse().join('') == String(x)){
      return true;
  } else {
    return false;
  }
};
```