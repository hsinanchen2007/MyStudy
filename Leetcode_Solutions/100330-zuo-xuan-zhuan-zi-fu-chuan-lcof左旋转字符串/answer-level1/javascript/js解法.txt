### 解题思路
拼接两个s字符串，从第n+1个取到第n+s.length个

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function(s, n) {
    return s.concat(s).slice(n,n+s.length);
};
```