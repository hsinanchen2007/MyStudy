```js
var diStringMatch = function(S) {
    let len = S.length;
    let res = [];
    let small = 0, big = len;
    for(let i = 0; i < len; i++) {
        if(S[i] === 'I') {
            res[i] = small++;
        } else {
            res[i] = big--;
        }
    }
    res[len] = big;
    return res;
};
```
