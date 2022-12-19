![1.png](https://pic.leetcode-cn.com/8d6d9f1dbce6194b2f19b36c71af4f024abc4df18f6623c7dce9e7375093eaf6-1.png)

### 解题思路
所幸代码还算整齐，击败率还算高

### 代码

```c
int area(int **grid, int i, int j, int size, int col){
	int s = 1;
	if (i > 0 && grid[i - 1][j] == 1){
		grid[i - 1][j] = 0;
		s += area(grid, i - 1, j, size, col);
	}
	if (i < size - 1 && grid[i + 1][j] == 1){
		grid[i + 1][j] = 0;
		s += area(grid, i + 1, j, size, col);
	}
	if (j > 0 && grid[i][j - 1] == 1){
		grid[i][j - 1] = 0;
		s += area(grid, i, j - 1, size, col);
		}
	if (j < col - 1 && grid[i][j + 1] == 1){
		grid[i][j + 1] = 0;
		s += area(grid, i, j + 1, size, col);
		}
	return s;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
	int max = 0, mt = 0;
	for (int i = 0; i < gridSize; i++)
		for (int j = 0; j < *gridColSize; j++)
			if (grid[i][j] == 1){
                grid[i][j] = 0;
				mt = area(grid, i, j, gridSize, *gridColSize);
				max = max>mt ? max : mt;
			}	
	return max;
}
```