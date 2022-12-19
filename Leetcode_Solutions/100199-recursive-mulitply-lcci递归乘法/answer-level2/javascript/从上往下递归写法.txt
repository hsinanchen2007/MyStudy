```javascript
var multiply = function(A, B) {
    return test(A, B, 0);
};

function test(A, B, sum) {
    let a = Math.min(A, B);
    let b = Math.max(A, B);
    if (a < 2) return b + sum;
    sum += b;
    return test(a - 1, b, sum)
}
```
