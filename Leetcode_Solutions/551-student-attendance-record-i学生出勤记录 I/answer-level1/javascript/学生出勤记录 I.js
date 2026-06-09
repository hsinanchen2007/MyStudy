
```js
var checkRecord = function(s) {
    if (s.indexOf('A') === s.lastIndexOf('A') && s.indexOf('LLL') === -1) {
        return true;
    } else {
        return false;
    }
};
```
*法二：正则匹配*
```js
var checkRecord = function(s) {
    let pat1 = /.*A+.*A+.*/;
    let pat2 = /L{3,}/;
    return !pat1.test(s) && !pat2.test(s);
};
```

