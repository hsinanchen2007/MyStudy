```
/**
 * @param {number} n
 * @param {number} m
 * @param {number[][]} indices
 * @return {number}
 */
var oddCells = function (n, m, indices) {
    let grids = Array.from({ length: n }, () => new Array(m).fill(0))
    let rows = new Map(), cols = new Map()
    indices.forEach(indice => {
        let x = indice[0], y = indice[1]
        rows.set(x, rows.has(x) ? rows.get(x) + 1 : 1)
        cols.set(y, cols.has(y) ? cols.get(y) + 1 : 1)
    })
    for (let i = 0; i < grids.length; i++) {
        if (rows.has(i)) {
            grids[i] = grids[i].map(it => it + rows.get(i))
        }
        for (let j = 0; j < grids[i].length; j++) {
            if (cols.has(j)) {
                grids[i][j] += cols.get(j)
            }
        }
    }
    let ans = 0
    grids.forEach(grid => {
        grid.forEach(g => {
            if (g !== 0 && g % 2 !== 0) {
                ans++
            }
        })
    })
    return ans
};
```
