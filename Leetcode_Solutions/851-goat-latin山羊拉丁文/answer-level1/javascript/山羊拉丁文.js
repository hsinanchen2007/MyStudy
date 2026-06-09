```js
var toGoatLatin = function(S) {
    let pat = /^[aeiou]/i;
    let sArr = S.split(' ');
    res = '';
    for (let i = 0; i < sArr.length; i++) {
        if (!pat.test(sArr[i])) {
            sArr[i] = sArr[i].substr(1) + sArr[i][0] 
        }
        res += sArr[i] + 'ma' + 'a'.repeat(i+1) + ' '
    }
    return res.replace(/[\s]$/, '')
};
```

