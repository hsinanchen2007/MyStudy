```
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function (n) {
    let arr = ('' + n).split('')
    let add = arr.reduce((pre, cur) => 1 * pre + 1 * cur)
    let mul = arr.reduce((pre, cur) => pre * cur)
    return mul - add
};
```
