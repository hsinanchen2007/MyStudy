最好时间164ms
```
var reverseString = function(s) {
    let i = 0,
        x = s.length -1;
    while (i < x) {
        [s[i], s[x]] = [ s[x], s[i] ]
        i++
        x--
    }
    return s
};
```
