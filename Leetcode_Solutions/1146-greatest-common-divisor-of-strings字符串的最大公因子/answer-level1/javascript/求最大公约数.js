### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    // 求最大公约数
    const gcd = (a, b) => {
        if (b === 0) {
            return a
        }
        return gcd(b, a % b)
    }
    if (str1 + str2 !== str2 + str1){
        return ''
    }
    const length = gcd(str1.length, str2.length)
    return str1.substring(0, length)
};

```