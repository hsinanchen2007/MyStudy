题目给的是方块，grid.length = grid[0].length

```js
var projectionArea = function(grid) {
    let left = 0;
    let right = 0;
    let up = 0;
    let n = grid.length;
    for (let i = 0; i < n; i++) {
        left += Math.max(...grid[i])
        let temp = []
        for (let j = 0; j < n; j++) {
            if (grid[i][j] !== 0) {
                up++
            }
            temp.push(grid[j][i])
        }
        right += Math.max(...temp)
    } 
    return left + right + up
};
```

