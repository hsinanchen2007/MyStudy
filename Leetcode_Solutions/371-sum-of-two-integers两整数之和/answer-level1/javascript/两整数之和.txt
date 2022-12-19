```js
var getSum = function(a, b) {
    if (a === 0 && b === 0) {
        return 0;
    }
    if (a === 0) {
        return b;
    }
    if (b === 0) {
        return a;
    }
    if (a > 0) {
        while (a > 0) {
            a--;
            b++;
        }
        return b;
    } else {
        while (a < 0) {
            a++;
            b--;
        }
        return b;
    }
};
```
