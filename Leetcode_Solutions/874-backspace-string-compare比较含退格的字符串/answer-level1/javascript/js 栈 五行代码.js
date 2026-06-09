```
var backspaceCompare = function(S, T) {
    let a = S.split('').reduce((pre, cur) => {
        return pre == '#' ? (cur == "#" ? '' : cur) : (cur == "#" ? pre.slice(0, pre.length - 1) : pre + cur);
    })
    let b = T.split('').reduce((pre, cur) => {
        return pre == '#' ? (cur == "#" ? '' : cur) : (cur == "#" ? pre.slice(0, pre.length - 1) : pre + cur);
    })
    return a == b;
};
```
