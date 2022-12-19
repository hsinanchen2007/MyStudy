```js
var firstUniqChar = function(s) {
    let sMap = {}
    for (const v of s) {
        var vNum = sMap[v]
        sMap[v] = vNum ? vNum + 1 : 1
    }
    
    for (const v of s) {
        if (sMap[v] === 1) return v
    }

    return ' '
};
```