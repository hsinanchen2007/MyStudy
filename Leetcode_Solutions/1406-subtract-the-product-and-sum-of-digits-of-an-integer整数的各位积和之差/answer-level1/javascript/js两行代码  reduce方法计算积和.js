```
var subtractProductAndSum = function (n) {
    n = n.toString().split('');
    return n.reduce((x, y) => (x * y)) - n.reduce((x, y) => (+x) + (+y));
};
```
