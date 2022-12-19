```js
var reverseLeftWords = function(s, n) {
    return s.concat(s).slice(n, n + s.length);
};
```