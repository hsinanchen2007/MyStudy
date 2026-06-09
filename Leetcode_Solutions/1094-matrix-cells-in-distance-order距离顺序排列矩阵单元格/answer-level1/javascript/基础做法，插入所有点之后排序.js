执行用时 : 256 ms, 在所有 JavaScript 提交中击败了 76.92% 的用户
内存消耗 : 49.3 MB, 在所有 JavaScript 提交中击败了 100.00% 的用户

```javascript
var allCellsDistOrder = function(R, C, r0, c0) {
    var res = [];
    for (let i = 0; i < R; ++i) {
        for (let j = 0; j < C; ++j) {
            let temp = [i, j];
            res.push(temp);
        }
    }
    res.sort((a, b) => {
        let ta = Math.abs(a[0]-r0) + Math.abs(a[1]-c0),
            tb = Math.abs(b[0]-r0) + Math.abs(b[1]-c0);
        return ta - tb;
    });
    return res;
};
```

大概是因为用 js 的人太少了叭