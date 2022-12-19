```js
var isIsomorphic = function(s, t) {
    if (s === t) {
        return true
    }
    for (let i = 0; i < s.length; i++) {
        if (s.indexOf(s[i]) !== t.indexOf(t[i])) {
            return false
        }
    }
    return true
};
```
