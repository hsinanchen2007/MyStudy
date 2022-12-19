![1.png](https://pic.leetcode-cn.com/148d7610cc9002ad66a5610c44d52d4f4b1f326aae0af934635cb4fdb17a4b1b-1.png)


### 解题思路
本题的难点是读懂题目。难道力扣出题的人语文考试都不及格吗？？
如果右面和下面出现三维体，表面积减少  接触面积*2

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
	int area = 0;
	for (int i = 0; i < gridSize; i++){
		for (int j = 0; j < *gridColSize; j++){
			if (grid[i][j]){
				area += grid[i][j] * 4 + 2;
				if (i < gridSize - 1 && grid[i + 1][j])
					area -= (grid[i][j] < grid[i + 1][j] ? grid[i][j] : grid[i + 1][j]) * 2;
				if (j < *gridColSize - 1 && grid[i][j + 1])
					area -= (grid[i][j] < grid[i][j + 1] ? grid[i][j] : grid[i][j + 1]) * 2;
			}
		}
	}
	return area;
}
```