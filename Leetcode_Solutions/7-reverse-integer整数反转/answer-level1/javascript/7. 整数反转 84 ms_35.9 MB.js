```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const negative = x < 0;
    if (negative) {
        x = -x;
    }
    x += '';
    let s = '';
    for (let c of x) {
        s = c + s;
    }
    s = negative ? -s : +s;
    const target = Math.pow(2, 31);
    if (s > target + 1 || s < -target) {
        return 0;
    }
    return s;
};
```