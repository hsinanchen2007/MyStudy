### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {

    str = str.trim();

    if (str[0] !== '+' && str[0] !== '-' 
            && (str[0] < '0' || str[0] > '9'))
        return 0

    let ans = 0, 
        sign = (str[0] === '+' || str[0] === '-') ? str[0] : ''

    for (let i = sign.length ? 1 : 0; i < str.length; i++) {
        if (str[i] < '0' || str[i] > '9') break

        ans = ans * 10 + (str.charCodeAt(i) - 48)
        if ((sign === '' || sign === '+') && ans > 2147483647) return 2147483647
        if (sign === '-' && ans > 2147483648) return -2147483648
    }

    return sign === '-' ? -ans : ans
};
```