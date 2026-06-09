``` javascript
var tree2str = function(t) {
    if (!t) {
        return ''
    }
    var left = tree2str(t.left)
    var right = tree2str(t.right)
    var res = `${t.val}`
    if (left || right) {
        res += `(${left})`
    }
    if (right) {
        res += `(${right})`
    }
    return res
};
```
