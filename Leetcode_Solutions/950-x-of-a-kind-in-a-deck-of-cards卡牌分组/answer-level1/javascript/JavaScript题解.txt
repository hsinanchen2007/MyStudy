代码行数稍微少点的写法：
```
var hasGroupsSizeX = function(deck) {
    function gcd(x, y) {
        return x == 0 ? y : gcd(y%x, x);
    }

    let obj = {};
    for(let i of deck) {
        obj[i] = !obj[i] ? 1 : ++obj[i];
    }

    let arr = Object.values(obj);
    let res = arr[0];
    return arr.every(i => (res = gcd(res, i)) > 1);
}
```
