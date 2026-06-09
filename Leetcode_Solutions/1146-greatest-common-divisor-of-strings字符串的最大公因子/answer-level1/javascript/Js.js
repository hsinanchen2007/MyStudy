### 解题思路
欧几里得算法:
```
 function gcd(num1, num2) {
    return num2 === 0 ? num1 : gcd(num2, num1 % num2);
  }
```

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function (str1, str2) {
  // 不相等则间接说明了不存在字符串X
  if (str1 + str2 !== str2 + str1) {
    return '';
  }
  function gcd(num1, num2) {
    // 利用辗转相除法来计算最大公约数，即字符串X在字符串str1中截止的索引位置
    return num2 === 0 ? num1 : gcd(num2, num1 % num2);
  }
  // 截取匹配的字符串
  return str1.substring(0, gcd(str1.length, str2.length));
};
```