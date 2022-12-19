```
var isOneBitCharacter = function (bits) {
    if (bits.length === 1) return true
    for (let i = 0; i < bits.length; i++) {
        let cur = bits[i]
        if (cur === 1) {
            i += 1
        }
        if (i + 2 === bits.length) {
            return true
        }

    }
    return false
};
```
