  var surfaceArea = function (grid) {
    let count = 0, sum = 0
    for (let i = 0; i < grid.length; i++) {
      for (let j = 0; j < grid[i].length; j++) {
        sum += grid[i][j]
        if (grid[i][j] > 1) {
          count += grid[i][j] - 1
        }
        if (grid[i][j + 1]) {
          count += Math.min(grid[i][j], grid[i][j + 1])
        }
        if (grid[i + 1]) {
          if (grid[i + 1][j]) {
            count += Math.min(grid[i][j], grid[i + 1][j])
          }
        }
      }
    }
    return sum * 6 - (count * 2)
  };