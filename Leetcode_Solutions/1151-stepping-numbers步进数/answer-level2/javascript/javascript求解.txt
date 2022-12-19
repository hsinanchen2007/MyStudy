
```js
/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
var countSteppingNumbers = function(low, high) {
    let res = [];
    if(low === 0) {
        res.push(0);
    }
    const dsp = function (result, curr) {
        if(curr >= low && curr <= high) {
            result.push(curr);
        }
        if (curr > high / 10) {
            return ;
        }
        let r = curr % 10;
        if (r != 9 && curr * 10 + r + 1 <= high) {
            dsp(result, curr * 10 + r + 1);
        }
        if (r != 0 && curr * 10 + r - 1 <= high) {
            dsp(result, curr * 10 + r - 1);
        }
    }
    for(let i = 1; i <= 9; i++) {
        dsp(res, i);
    }
    res.sort((a, b) => a - b);
    return res;
};
```
