```js
var bitwiseComplement = function(N) {
    let NTo2 = N.toString(2)
    let len = NTo2.length;
    let res2 = ''
    for (let i = 0; i < len; i++) {
        if (NTo2[i] == 1) {
            res2 += 0
        } else {
            res2 += 1
        }
    }
    return parseInt(res2,2)
};
```
