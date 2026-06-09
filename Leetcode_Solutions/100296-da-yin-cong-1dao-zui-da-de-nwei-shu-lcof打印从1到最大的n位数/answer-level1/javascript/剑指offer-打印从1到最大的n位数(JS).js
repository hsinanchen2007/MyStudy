```js
var printNumbers = function(n) {
    let result = [];
    for (let i = 1; i < Math.pow(10, n); i++) {
        result.push(i);
    }
    return result;
};
```