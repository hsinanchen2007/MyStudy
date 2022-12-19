### 解题思路
关键在于求最大公约数
### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
   // 求两个数的最大公约数
   function gcd (a, b) {
       return b === 0 ? a : gcd(b, a % b)
   }
   if (str1 + str2 !== str2 + str1) {
       return ''
   }
   return str1.substring(0, gcd(str1.length, str2.length))
};
```