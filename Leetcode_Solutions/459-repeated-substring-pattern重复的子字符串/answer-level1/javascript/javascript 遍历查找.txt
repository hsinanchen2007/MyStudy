### 解题思路
遍历进行查找

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function(s) {
  let rigth = 1;
  let len = s.length;
  while (rigth <= s.length / 2) {
    if (len % rigth === 0) {
      for (let index = rigth; index < s.length; index++) {
        if (s[index] !== s[index % rigth]) {
          rigth += 1;
          break;
        } else {
          if (index === s.length - 1) return true;
        }
      }
    } else {
      rigth += 1;
    }
  }
  return false;
};
```