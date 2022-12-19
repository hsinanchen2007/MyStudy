从下到上递归方式实现

```javascript
var multiply = function(A, B) {
    const a = Math.min(A, B);
    const b = Math.max(A, B);
    if (a < 2) return b;
    const lastResult = multiply(a-1,b);
    result = b + lastResult;
};
```
