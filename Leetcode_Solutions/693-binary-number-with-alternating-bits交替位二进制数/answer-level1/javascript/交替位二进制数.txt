```js
var hasAlternatingBits = function(n) {
    let nto2 = n.toString(2);
    let pat = /^1(01)*0?$/;
    return pat.test(nto2);
};
```

