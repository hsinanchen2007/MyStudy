```javascript []
var myAtoi = function(str) {
    let num = parseInt(str.trim());
    if(!num) return 0;
    return Math.max( Math.min(num, 2 ** 31 - 1), - (2 ** 31));
}
```

