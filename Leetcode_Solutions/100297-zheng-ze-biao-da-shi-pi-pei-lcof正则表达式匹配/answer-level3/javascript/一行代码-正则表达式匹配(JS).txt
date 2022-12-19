```js
var isMatch = function(s, p) {
    return new RegExp("^" + p + "$", "g").test(s);
};
```