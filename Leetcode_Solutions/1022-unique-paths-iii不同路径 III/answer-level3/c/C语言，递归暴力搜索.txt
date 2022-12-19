### 解题思路
0ms100%, 7M,15%

深度递归：扣除一个起点一个终点，预先对-1计数，那么可以精确的知道 对于正确路径应当走多少步0到达2.
记忆化：需要标记走过的路。开始搜索后只有0和2是可能合法的，因此标记1即可。
回溯：每层递归退出时要回退掉本层标记的节点。
剪枝：为了加速，增加了方向变量dir，如果上一级是从左往右过来的，本次不会再向左。

### 代码

```c

#define check_node(a, i, j) (i >= 0 && i < row && (j) >= 0 && (j) < col)
#define pro(i, j, max, dir)                                                              \
	if (check_node(grid, i, j))                                                      \
	dfs(grid, i, j, max, dir)
int cnt, row, col;
void dfs(int **grid, int i, int j, int max, int dir)
{
	if (!max) {
		if (grid[i][j] == 2) 
			cnt++;
		return;
	}
	if (grid[i][j]) //走过的节点
		return;
    
	grid[i][j] = 1;
	max--;

	if (dir != 2)
		pro(i - 1, j, max, 1);
	if (dir != 1)
		pro(i + 1, j, max, 2);
	if (dir != 4)
		pro(i, j - 1, max, 3);
	if (dir != 3)
		pro(i, j + 1, max, 4);

	grid[i][j] = 0;//回退
}

int uniquePathsIII(int **grid, int gridSize, int *gridColSize)
{
	cnt = 0;
	int i, j;//起点坐标
	col = *gridColSize;
	row = gridSize;
	int max = col * row - 2;//扣除起止点

	for (int ii = 0; ii < row; ii++)
		for (int jj = 0; jj < col; jj++)
			if (grid[ii][jj] == 1)
				i = ii, j = jj;
			else if (grid[ii][jj] == -1)
				max--;

	pro(i - 1, j, max, 1);
	pro(i + 1, j, max, 2);
	pro(i, j - 1, max, 3);
	pro(i, j + 1, max, 4);

	return cnt;
}

```