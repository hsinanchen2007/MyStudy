```js
var reverseString = function(s) {
    var length = s.length;
    var middle = Math.floor(s.length/2)
    for (let i = 0; i < middle; i++) {
        var temp = s[i];
        s[i] = s[length-i-1];
        s[length-i-1] = temp;
    }
    return s
};
```

