```
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    const num = Number('1' + Array(n).fill('0').join(''))
    const arr = []
    for (let a = 1;a < num; a++) {
        arr.push(a)
    }
    return arr
};
```
