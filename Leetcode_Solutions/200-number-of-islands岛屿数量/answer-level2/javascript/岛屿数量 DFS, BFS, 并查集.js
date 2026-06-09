解法一 DFS
```

// time complexity: O(M*N)
// space complexity: O(M*N)
var numIslands = function(grid) {
    let len_r = grid.length;
    if (!len_r) return 0;
    let len_c = grid[0].length;
    let num_islands = 0;
    for (let r = 0; r < len_r; r++) {
      for (let c = 0; c < len_c; c++) {
        if (grid[r][c] == '1') {
          ++num_islands;
          dfsGrid(grid, r, c);
        }
      }
    }

    return num_islands;
};

function dfsGrid(grid, r, c) {
    let len_r = grid.length;
    let len_c = grid[0].length;

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c); 
    if (r + 1 < len_r && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < len_c && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
}
```
解法二 BFS
```

//time complexity : O(M*N)
//space complexity: O(M*N)
var numIslands = function(grid) {
    let len_r = grid.length;
    if (!len_r) return 0;
    let len_c = grid[0].length;

    let num_islands = 0;
    for (let r = 0; r < len_r; r++) {
        for (let c = 0; c < len_c; c++) {
            if (grid[r][c] == '1') {
                num_islands++;
                grid[r][c] = '0'; //marked as visited
                let neighbors = [[r,c]];
                bfsGrid(grid, neighbors);
            }
        }
    }

    return num_islands;
};

function bfsGrid(grid, neighbors) {
    let len_r = grid.length;
    if (!len_r) return 0;
    let len_c = grid[0].length;

    while (neighbors.length > 0) {
        let neighbor = neighbors.shift();
        let row = neighbor[0];
        let col = neighbor[1];
        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
            neighbors.push([row - 1, col]);
            grid[row - 1][col] = '0';
        }
        if (row + 1 < len_r && grid[row + 1][col] == '1') {
            neighbors.push([row + 1, col]);
            grid[row + 1][col] = '0';
        }
        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
            neighbors.push([row, col - 1]);
            grid[row][col - 1] = '0';
        }
        if (col + 1 < len_c && grid[row ][col + 1] == '1') {
            neighbors.push([row, col + 1]);
            grid[row][col + 1] = '0';
        }
    }
}
```
解法三、并查集


