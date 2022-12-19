```
var decodeString = function (s) {
    let num = ""
    let unit = ""
    let stack = []
    for (let char of s) {
        if (char == '[') {
            const item = [num, unit]
            stack.push(item)
            unit = ""
            num = ""
        } else if (char == ']') {
            const out = stack.pop()
            let curRes = ""
            for (let index = 0; index < out[0]; index++) {
                curRes += unit
            }
            curRes = out[1] + curRes
            unit = curRes
        } else if(!isNaN(parseInt(char))) {
            num += char
        } else {
            unit += char
        }
    }
    return unit
};
```
