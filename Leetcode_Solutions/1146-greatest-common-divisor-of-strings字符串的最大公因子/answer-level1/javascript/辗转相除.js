### 解题思路
辗转相除法 求最大公因数 gcd

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    let len1 = str1.length
    let len2 = str2.length
    let x = str1.substring(0, gcd(len1, len2)) 
    if(check(x, str1) && check(x, str2)) return x 
    return ''
};
const gcd = (a, b) => b === 0 ? a : gcd(b, a % b) 
const check = (x, str) => {
    let ans = ''
    while (ans.length < str.length) {
        ans += x
    }
    return ans == str
}
```