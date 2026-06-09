
```
var isUnique = function(astr) {
    let unique = [...new Set(astr)];
    return unique.length === astr.length;
};
```
