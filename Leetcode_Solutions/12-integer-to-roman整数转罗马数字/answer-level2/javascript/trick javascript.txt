```javascript
/**
 * @param {number} num
 * @return {string}
 */
var map = [
    {
        a: 'I',
        b: 'V',
        c: 'X'
    },
    {
        a: 'X',
        b: 'L',
        c: 'C'
    },
    {
        a: 'C',
        b: 'D',
        c: 'M'
    },
    {
        a: 'M'
    }
];
var intToRoman = function(num) {
    var result = '';
    var tag = 0;
    while(num) {
        var r = num % 10;
        num = Math.floor(num / 10);
        var {a, b, c} = map[tag];
        if (r === 4) {
            result = a + b + result;
        }
        else if (r === 9) {
            result = a + c + result;
        }
        else if (r < 4) {
            result = new Array(r).fill(a).join('') + result;
        }
        else {
            result = b + new Array(r - 5).fill(a).join('')  + result;
        }
        tag ++;
    }
    return result;
};
```
