```js
var lastRemaining = function(n, m) {
    let result = 0;
    for(let i = 2; i < n + 1; i++){
        result = (result + m) % i
    }
    return result;
};
```