### 解题思路
用Regular Expression来解决这个问题

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
 if (str && str.trim()) {
     const regex = /^[+|-]?\d+/;
     const matchedResults = regex.exec(str.trim());
     if (matchedResults) {
         return Math.max(Math.min(parseInt(matchedResults[0]), (Math.pow(2, 31) - 1)), -1 * Math.pow(2, 31));
     }
 }
 return 0;
};
```