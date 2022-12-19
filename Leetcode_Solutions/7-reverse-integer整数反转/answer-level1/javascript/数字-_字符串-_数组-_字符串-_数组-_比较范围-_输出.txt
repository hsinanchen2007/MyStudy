### 解题思路




```
代码块
```
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let result
    const str = x.toString()
    const firstChar = str.charAt()
    if (x < 0) {
        result = parseInt(firstChar + str.split('').splice(1).reverse().join(''))
    } else {
        result = parseInt(str.split('').reverse().join(''))
    }
    if (result < Math.pow(-2, 31) || result > (Math.pow(2, 31) - 1)) {
        return 0
    } else {
        return result
    }
};
```