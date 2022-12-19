```javascript
var reverse = function(x) {
    const border = 2**31
    const max = border - 1
    const min = -border

    const result = (x > 0 ? 1 : -1) * String(x).split('').filter(x => x !== '-').reverse().join('')
    return result > max || result < min ? 0 : result 
};
```