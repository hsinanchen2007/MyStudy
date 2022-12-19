```
var findTheDifference = function(s, t) {
    var total = 0
    for (var i =0; i < s.length; i++) {
        total -= s.charCodeAt(i)
        total += t.charCodeAt(i)
    }
    return String.fromCharCode(total + t.charCodeAt(i))
};
```
