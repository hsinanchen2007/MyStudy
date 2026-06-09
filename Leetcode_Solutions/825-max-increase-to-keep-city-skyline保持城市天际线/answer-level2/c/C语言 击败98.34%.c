### 解题思路
算天际线，然后逐个算高度即可
![image.png](https://pic.leetcode-cn.com/3a2138425fc12a66017e719671e7b3f278abd6fe4754c9e16f1463ed4b487264-image.png)

### 代码

```c
int maxCol(int** grid, int gridSize, int gridColSize, int **colMax)
{
	int i, j;
	int *lCol = (int*)calloc(gridColSize, sizeof(int));
	if (lCol == NULL) {
		return -1;
	}
	for (i = 0; i < gridColSize; i++) {
		for (j = 0; j < gridSize; j++) {
			lCol[i] = lCol[i] > grid[j][i] ? lCol[i] : grid[j][i];
		}
	}
	*colMax = lCol;
	return 0;
}
int maxRow(int** grid, int gridSize, int gridColSize, int **rowMax)
{
	int i, j;
	int *lRow = (int*)calloc(gridSize, sizeof(int));
	if (lRow == NULL) {
		return -1;
	}
	for (i = 0; i < gridSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			lRow[i] = lRow[i] > grid[i][j] ? lRow[i] : grid[i][j];
		}
	}
	*rowMax = lRow;
	return 0;
}
int getGrowHeight(int** grid, int gridSize, int gridColSize, int *rowMax, int *colMax, int x, int y)
{
	int maxHeight;
	if (x >= gridSize || y >= gridColSize) {
		return 0;
	}
	maxHeight = rowMax[x] < colMax[y] ? rowMax[x] : colMax[y];
	return maxHeight - grid[x][y];
}
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
	int i, j;
	int rlt = 0;
	int *colMax = NULL;
	int *rowMax = NULL;
	maxCol(grid, gridSize, gridColSize[0], &colMax);
	maxRow(grid, gridSize, gridColSize[0], &rowMax);
	for (i = 0; i < gridSize; i++) {
		for (j = 0; j < gridColSize[0]; j++) {
			rlt += getGrowHeight(grid, gridSize, gridColSize[0], rowMax, colMax, i, j);
		}
	}
	free(colMax);
	free(rowMax);
	return rlt;
}
```