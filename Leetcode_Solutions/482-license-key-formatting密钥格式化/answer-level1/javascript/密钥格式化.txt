*法一*

```js
var licenseKeyFormatting = function(S, K) {
    S = S.toUpperCase().replace(/\-/g,'');
    let index = S.length % K;
    let s1 = S.slice(0,index);
    let s2 = S.slice(index);
    let count = s2.length/K;
    var arr = [];
    for(let i = 0; i < count; i++) {
        arr.push(s2.substr(i*K, K))
    }
    if (s1 !== '') {
        arr.unshift(s1)
    }
    return arr.join('-');
};
```

*法二：逆序插入*

```js
var licenseKeyFormatting2 = function(S, K) {
    S = S.replace(/-/g, '')
    let res = ''
    let i = S.length - K
    while (i + K > 0) {
        res = (i > 0 ? '-' : '') + S.substring(i, i + K) + res
        i -= K
    }
    return res.toUpperCase()
};
```

