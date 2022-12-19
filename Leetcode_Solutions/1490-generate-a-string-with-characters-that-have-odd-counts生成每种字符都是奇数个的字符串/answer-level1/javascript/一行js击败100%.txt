```js
var generateTheString = function(n) {
    return "b".repeat(n-1) + (n%2 == 0 ? "a" : "b");
};
```