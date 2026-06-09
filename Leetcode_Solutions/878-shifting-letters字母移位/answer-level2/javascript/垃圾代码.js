```
/**
 * @param {string} S
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(S, shifts) {
    let sum = 0
    const base = 'a'.charCodeAt(0)
    const arr = S.split('')
    let res = ''
    for(let j = shifts.length - 1;j > -1;j--) {
        sum += shifts[j]
        arr[j] = String.fromCharCode(base + (arr[j].charCodeAt(0) - base + sum) % 26)
    }
    return arr.join('')
};
```
