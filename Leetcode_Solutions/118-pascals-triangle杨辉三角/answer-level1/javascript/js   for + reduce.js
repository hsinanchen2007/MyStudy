```
var generate = function(numRows) {
    if (!numRows) return []
    let r = Array(numRows)
    r[0] = [1]
    for (let i=1;i<numRows;i++) {
        r[i] = []
        r[i-1].reduce((p,c) => {
            r[i].push(p+c)
            return c
        },0)
        r[i].push(1)
    }
    return r
};
```
