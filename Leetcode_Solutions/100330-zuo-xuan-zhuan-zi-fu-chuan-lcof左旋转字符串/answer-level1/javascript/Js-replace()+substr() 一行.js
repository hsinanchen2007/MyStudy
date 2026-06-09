### 解题思路
replace()+substr() 一行

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function(s, n) {
     return s.replace(s.substr(0, n), '') + s.substr(0,n)
};
```
<!-- 只用substr()
```
var reverseLeftWords = function (s, n) {
  return s.substr(n) + s.substr(0, n)
};
``` 
-->