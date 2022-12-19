```javascript
var strStr = function(haystack, needle) {
  const symbol = String(Symbol('Symbol'))
  const replaceStr = haystack.replace(needle, symbol)
  return replaceStr.indexOf(symbol);
};
```
