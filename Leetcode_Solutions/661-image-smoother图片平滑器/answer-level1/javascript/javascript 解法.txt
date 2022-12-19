```
var imageSmoother = function (M) {
    let rows = M.length, cols = M[0].length
    let ret = new Array(rows).fill(0).map(_ => new Array(cols).fill(0))
    for (let r = 0; r < rows; ++r) {
        for (let c = 0; c < cols; ++c) {
            let count = 0
            for (let x of [-1, 0, 1])
                for (let y of [-1, 0, 1])
                    if (isValid(r + x, c + y, rows, cols)) {
                        count++
                        ret[r][c] += M[r + x][c + y]
                    }
            ret[r][c] = Math.floor(ret[r][c] / count)
        }
    }
    return ret
};
const isValid = (r, c, rows, cols) =>
    r < rows && r >= 0 && c < cols && c >= 0

```
