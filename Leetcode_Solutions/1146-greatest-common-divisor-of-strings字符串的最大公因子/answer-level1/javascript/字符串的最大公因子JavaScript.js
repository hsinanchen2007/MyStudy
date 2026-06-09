### 解题思路
辗转相除

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function (str1, str2) {
    const gcd = function (num1, num2) {
        return num2 === 0 ? num1 : gcd(num2, num1 % num2)
    }

    if(str1 + str2 === str2 + str1){
        let len1 = str1.length, len2 = str2.length
        let len = len1 > len2 ? gcd(len1, len2) : gcd(len2, len1)
        return str1.substring(0, len)
    }else{
        return ""
    }
};
```