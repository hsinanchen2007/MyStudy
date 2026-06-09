### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let limit = 2**31
    let min = -limit
    let pre = 1
    if (x < 0) {
        pre = -1
    }
    let num = Number(String(Math.abs(x)).split('').reverse().join(''))
    let result = pre * num
    return (result >= limit) || (result <= min) ? 0 : result
};
```