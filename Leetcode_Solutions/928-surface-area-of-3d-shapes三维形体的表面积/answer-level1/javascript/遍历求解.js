```js
var surfaceArea = function(grid) {
    let xLen = grid.length;
    let yLen = grid[0].length;
    let allSurface = 0;
    let sameSurface = 0; 
    for(let i=0; i<xLen; i++){
        for(let j=0; j<yLen; j++){
            allSurface +=  grid[i][j] != 0 ? (grid[i][j] * 4 + 2) : 0;
            sameSurface += j+1<yLen ? Math.min(grid[i][j], grid[i][j+1]) : 0;
            sameSurface += j-1>=0 ? Math.min(grid[i][j], grid[i][j-1]) : 0; 
            sameSurface += i+1<xLen ? Math.min(grid[i][j], grid[i+1][j]) : 0; 
            sameSurface += i-1>=0 ? Math.min(grid[i][j], grid[i-1][j]) : 0; 
        }
    }
    return allSurface - sameSurface;
};
```
