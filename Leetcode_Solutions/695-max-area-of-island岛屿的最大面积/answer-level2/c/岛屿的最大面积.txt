### 解题思路
明显递归 
-设置为0后不会影响新的计数（因为不会连着，如果连着，已经被计过了）
-不设置为0，自身计数可能会被重复计算

### 代码

```c
int countArea(int** grid, int i, int j, int gridSize, int* gridColSize){
	grid[i][j] = 0;
    int cnt = 1;
	if (i + 1 < gridSize && grid[i+1][j])
        cnt += countArea(grid, i + 1, j,gridSize, gridColSize);
	if (i - 1 >= 0  && grid[i-1][j])
		cnt += countArea(grid, i - 1, j,gridSize, gridColSize);
	if (j + 1 < gridColSize[i] && grid[i][j+1])
		cnt += countArea(grid, i, j + 1,gridSize, gridColSize);
	if (j - 1 >= 0 && grid[i][j-1])
		cnt += countArea(grid, i, j - 1, gridSize, gridColSize);
	return cnt;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
	int max = 0, tmp = 0;
	for (int i = 0; i <gridSize; i++)
		for (int j = 0; j< gridColSize[i]; j++)
			if (grid[i][j]) {
				tmp = countArea(grid, i, j, gridSize, gridColSize);
				max = max > tmp ? max : tmp;
			}
	return max;
}
```