一行代码搞定，用concat好像比用加号更快
```javascript
/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function(s, n) {
    return s.slice(n).concat(s.slice(0, n));
};
```
