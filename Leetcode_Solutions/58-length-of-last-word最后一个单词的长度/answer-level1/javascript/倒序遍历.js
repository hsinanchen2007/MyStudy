没有多余的分支判断，也没有花里胡哨的语法糖

```javascript
var lengthOfLastWord = function(s) {
  let start = -1, end = -1
  for (let i = s.length - 1; i > -1; i--) {
    if (end === -1 && s[i] !== ' ') { end = i }
    if (end !== -1 && s[i] === ' ') { start = i; break; }
  }
  return end - start
};
```