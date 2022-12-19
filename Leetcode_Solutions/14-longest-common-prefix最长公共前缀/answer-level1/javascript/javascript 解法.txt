有优化的地方 希望请教 
```
var longestCommonPrefix = function(strs) {
    if(!strs.length) return ''
    return strs.reduce((k,m) => {
        var str = ''
        for(let [i,st] of Object.entries(m)) {
            if(k.charAt(i) !== st) {
                break
            } else {
                str += st
            }
        }
        return str
    })
};
```
