```javascript
var subtractProductAndSum = function(n) {
    return n.toString().split("").map(e => parseInt(e)).reduce((acc, e) => acc * e, 1) - n.toString().split("").map(e => parseInt(e)).reduce((acc, e) => acc + e, 0)
};
```
