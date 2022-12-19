```js
var isSubsequence2 = function(s, t) {
    if (s.length === 0) {
        return true;
    }
    let sPos = 0;
    let tPos = 0;
    let sLen = s.length;
    let tLen = t.length;
    while (tPos < tLen) {
        if (s[sPos] === t[tPos]) {
            sPos++
        }
        if (sPos === sLen) {
            return true
        }
        tPos++
    }
    return false;
};
```
