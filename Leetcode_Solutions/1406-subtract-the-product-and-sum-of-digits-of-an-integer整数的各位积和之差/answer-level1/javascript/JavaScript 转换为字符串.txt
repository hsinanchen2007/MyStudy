### 解题思路


### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    const strArr = n.toString().split('')
    const len = strArr.length
    if (len === 1) {
        return 0
    }
    let product = 1
    let sum = 0
    strArr.forEach(str => {
        const num = parseInt(str)
        product *= num
        sum += num
    })
    return product - sum
};
```