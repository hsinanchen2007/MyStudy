### 解题思路
先用正则匹配数字，然后一个个过条件过一遍就行了

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var strToInt = function(str) {
    const regMatch = str.match(/^\s*([-|+]?\d+).*$/)
    if(!regMatch || regMatch[1] === undefined) return 0
    const num = +regMatch[1]
    const max = 2147483647
    const min = -2147483648
    if(isNaN(num))return 0
    if(num >= max) return max
    if(num < min) return min
    return num
};
```