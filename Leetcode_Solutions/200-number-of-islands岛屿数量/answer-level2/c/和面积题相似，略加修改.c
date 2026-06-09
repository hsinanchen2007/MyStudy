![1.png](https://pic.leetcode-cn.com/713b0a1fe078f88996b6b52ce55c0feee326c83189524566abd595b0c15340c3-1.png)

### 解题思路
此处撰写解题思路

### 代码

```c
void area(char **grid, int i, int j, int size, int col){
	if (i > 0 && grid[i - 1][j] == '1'){
		grid[i - 1][j] = 0;
		area(grid, i - 1, j, size, col);
	}
	if (i < size - 1 && grid[i + 1][j] == '1'){
		grid[i + 1][j] = 0;
		area(grid, i + 1, j, size, col);
	}
	if (j > 0 && grid[i][j - 1] == '1'){
		grid[i][j - 1] = 0;
		area(grid, i, j - 1, size, col);
	}
	if (j < col - 1 && grid[i][j + 1] == '1'){
		grid[i][j + 1] = 0;
		area(grid, i, j + 1, size, col);
	}
}
int numIslands(char** grid, int gridSize, int* gridColSize){
	int land = 0;
	for (int i = 0; i < gridSize; i++)
		for (int j = 0; j < *gridColSize; j++)
			if (grid[i][j] == '1'){
				grid[i][j] == 0;
				area(grid, i, j, gridSize, *gridColSize);
				land++;
			}		
	return land;
}
```