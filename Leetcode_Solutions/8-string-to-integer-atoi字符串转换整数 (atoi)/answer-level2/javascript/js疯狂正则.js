### 解题思路
好恶心的测试样例

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    str = str.trimStart()
    let mul = 1
    if(!str) {
        return 0
    }
    else if(str[0].match(/\+|-/)) {
        if(str[0].match(/-/)) {
            mul = -1
        }
        str = str.replace(/\+|-/, '')
    }

    if(!str) {
        return 0
    }
    else if(!str[0].match(/\d/)) {
        return 0
    }
    
    let strNumber = str.match(/^(\+|-|\d)\d*\.*\d*/)
    let number = parseInt(strNumber) * mul
    if(number > Math.pow(2, 31) - 1) {
        return Math.pow(2, 31) - 1
    }
    else if(number < -Math.pow(2, 31)) {
        return -Math.pow(2, 31)
    }
    else return number
};
```