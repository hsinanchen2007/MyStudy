```
/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number = function (num) {
    let arr = (''+num).split(''), i = arr.indexOf('6')
    if (~i) {
        arr[i] = '9'
    }

    return arr.join('') * 1

};
```
