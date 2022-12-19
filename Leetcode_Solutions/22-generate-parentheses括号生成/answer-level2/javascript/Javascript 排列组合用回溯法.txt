### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
  let result = []
  function backtrace(str, left, right) {
      if (str.length === 2 * n) {
          result.push(str);
          return
      }
      if (right < left) {
        backtrace(str + ')',  left, right + 1)
      }
      if (left < n) {
        backtrace(str + '(', left + 1, right)
      }
  };
  backtrace('', 0, 0);
  return result
};
```