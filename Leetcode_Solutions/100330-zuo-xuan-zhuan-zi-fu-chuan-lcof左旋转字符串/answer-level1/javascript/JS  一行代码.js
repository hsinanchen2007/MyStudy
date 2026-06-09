### 代码

```javascript
var reverseLeftWords = function(s, n) {
    return s.substr(n)
            .concat(s.substr(0, n))
};
```