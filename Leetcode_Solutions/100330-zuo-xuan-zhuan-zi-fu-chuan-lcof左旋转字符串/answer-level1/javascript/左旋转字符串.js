### 解题思路
单行拼接一气呵成
### 代码

```javascript
/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function(s, n) {
    return s.slice(n).concat(s.slice(0, n))
};
```