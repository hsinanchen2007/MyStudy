```
var longestCommonPrefix = function(strs) {
    const {length} = strs
    let prefix = ''
    if (length <= 1) return strs[0] || prefix
    let firstStrLen = strs[0].length
    for(let i = 1; i <= firstStrLen; i++) {
        for(let j = 0; j < length - 1; j++) {
            const prevStr = strs[j].slice(0, i)
            const nextStr = strs[j + 1].slice(0, i)
            if (prevStr !== nextStr) return prefix
            if (j === length - 2) {
                prefix = prevStr
            }
        }
    }
    return prefix
};
```