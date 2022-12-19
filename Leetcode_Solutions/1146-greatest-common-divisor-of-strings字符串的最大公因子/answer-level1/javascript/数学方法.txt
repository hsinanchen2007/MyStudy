### 解题思路
当 str1 与 str2 存在非空的 X 为最大公因子时，

- 假设 str1 = n*X, str2 = m*X
   str1 + str2 = (n+m)*X = str2 + str1


### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
const gcd = (a, b) => (a % b === 0 ? b : gcd(b, a%b));

var gcdOfStrings = function(str1, str2) {
    if (str1 + str2 !== str2 + str1) return '';
    if (str1.length > str2.length) {
        return str2.substring(0, gcd(str1.length, str2.length));
    }
    return str1.substring(0, gcd(str2.length, str1.length));
};
```

###复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)