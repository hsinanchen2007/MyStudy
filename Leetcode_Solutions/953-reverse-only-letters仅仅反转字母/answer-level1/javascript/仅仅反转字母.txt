```js
var reverseOnlyLetters = function(S) {
    let pat = /[^a-zA-Z]/
    let pat2 = /[^a-zA-Z]/g
    // 符号位置
    let mark = new Map()
    for (let i = 0; i < S.length; i++) {
        if (pat.test(S[i])) {
            mark.set(i, S[i])
        }
    }
    let S2 = S.replace(pat2, '').split('').reverse();
    for (let [key, val] of mark) {
        S2.splice(key,0,val)
    }
    return S2.join('')
};
```
