```js
var isPowerOfThree = function(n) {
    while(n >= 3) {
        n /= 3
    }
    if (n === 1) {
        return true
    } else {
        return false
    }  
};
```
