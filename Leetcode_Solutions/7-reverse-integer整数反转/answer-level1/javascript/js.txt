```
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    if (x === 0) return 0
    if (x > 0) {
        const result = String(x).split('').reverse().join('')
        const max =  Math.pow(2, 31) - 1
        if (Number(result) <=  max) {
            return Number(result)
        } else {
            return 0
        }
    } else {
        const result = String(x).split('-')[1].split('').reverse().join('')
        const min = Math.pow(2, 31) * -1
        if (Number(result) * -1 >= min) {
            return Number(result) * -1
        } else {
            return 0
        }
    }
}
```
