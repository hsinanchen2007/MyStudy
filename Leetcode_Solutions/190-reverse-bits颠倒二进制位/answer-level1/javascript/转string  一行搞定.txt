```
var reverseBits = function(n) {
    return +('0b'+n.toString(2).padStart(32,0).split('').reverse().join(''))
};
```
