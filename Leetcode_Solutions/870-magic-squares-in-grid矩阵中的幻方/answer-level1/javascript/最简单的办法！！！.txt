```
/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function (grid) {
    let counter = 0;
    for (let i = 0; i + 2 < grid.length; i++) {
        for (let j = 0; j + 2 < grid[0].length; j++) {
            if (isMagic(grid, i, j)) counter++;
        }
    }
    return counter;
};

const isMagic = (grid, i, j) => {
    if (grid[i + 1][j + 1] !== 5) return false;
    const count = Array(16).fill(0);
    count[grid[i][j]]++;
    count[grid[i][j + 1]]++;
    count[grid[i][j + 2]]++;
    count[grid[i + 1][j]]++;
    count[grid[i + 1][j + 1]]++;
    count[grid[i + 1][j + 2]]++;
    count[grid[i + 2][j]]++;
    count[grid[i + 2][j + 1]]++;
    count[grid[i + 2][j + 2]]++;
    for (let i = 1; i <= 9; i++) {
        if (count[i] !== 1) return false;
    }
    return (
        grid[i][j] + grid[i][j + 1] + grid[i][j + 2] === 15 &&
        grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] === 15 &&
        grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] === 15 &&
        grid[i][j] + grid[i + 1][j] + grid[i + 2][j] === 15 &&
        grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] === 15 &&
        grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] === 15 &&
        grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] === 15 &&
        grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] === 15
    );
};
```
