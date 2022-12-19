```
var numIslands = function(grid) {
	const row = grid.length;
	if(!row) return 0;
	const col = grid[0].length;
	let res = 0;
	for(let i = 0; i < row; i++) {
		for(let j = 0; j < col; j++) {
			if(grid[i][j] === '1') {
				res++;
				dfs(grid, i, j);
			}
		}
	}
	function dfs(grid, i, j) {
		if(i < 0 || i >= row || j < 0 || j >= col) return;
		if(grid[i][j] === '1') {
			grid[i][j] = '0';
			dfs(grid, i - 1, j);
			dfs(grid, i + 1, j);
			dfs(grid, i, j - 1);
			dfs(grid, i, j + 1);
		}
	}
	return res;
};
```
