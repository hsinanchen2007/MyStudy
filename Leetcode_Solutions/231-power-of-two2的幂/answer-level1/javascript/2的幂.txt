*法一*

```js
var isPowerOfTwo = function(n) {
    while(n >= 2) {
        n /= 2
    }
    if (n === 1) {
        return true
    } else {
        return false
    }
};

var n = 0
console.log(isPowerOfTwo(n));
```

*法二*

```js
var isPowerOfTwo = function(n) {
    return Number.isInteger(Math.log2(n));
};
```
