### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
	let len = grid.length;
	let ylen = grid[0].length;
	for(let j = 1; j < ylen; j++) {
		grid[0][j] = grid[0][j-1] + grid[0][j];
	}
	for(let j = 1; j < len; j++) {
		grid[j][0] = grid[j-1][0] + grid[j][0];
	}
	for(let i = 1; i < len; i++) { 
		for(let j = 1 ; j < ylen; j++) {
			grid[i][j] = Math.min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
		}
	}
	return grid[len-1][ylen-1];
};
```