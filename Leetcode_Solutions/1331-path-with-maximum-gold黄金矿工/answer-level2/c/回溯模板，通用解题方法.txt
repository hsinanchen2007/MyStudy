### 解题思路
回溯模板，通用解题方法

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b)      ((a) > (b) ? (a) : (b))

static int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
static int visit[15][15];
static int row;
static int col;
static int tmp;
static int ans;

void dfs(int **map, int i, int j)
{
	int loop;
	int new_row;
	int new_col;
	if (i < 0 || j < 0 || i > row || j > col || map[i][j] == 0) {
		return;
	}
	visit[i][j] = 1;
	//printf("%d + [%d %d] = %d\n", tmp, i, j, tmp + map[i][j]);
	tmp += map[i][j];
	ans = MAX(ans, tmp);
	for (loop = 0; loop < 4; loop++) {
		new_row = i + dir[loop][0];
		new_col = j + dir[loop][1];
		if (new_row >=0 && new_row <= row &&
		    new_col >=0 && new_col <= col) {
			if (!visit[new_row][new_col] && map[new_row][new_col] > 0) {
				dfs(map, new_row, new_col);
			}
		}
	};
	visit[i][j] = 0;
	tmp -= map[i][j];
	if (tmp < 0)
		printf("%d\n", tmp);
}


int getMaximumGold(int **grid, int gridSize, int *gridColSize)
{
	int i;
	int j;
	if (!grid || gridSize == 0 || *gridColSize == 0)
		return 0;
	row = gridSize - 1;
	col = *gridColSize - 1;
	tmp = 0;
	ans = 0;
	memset(visit, 0, sizeof(visit));
	for (i = 0; i < gridSize; i++) {
		for (j = 0; j < *gridColSize; j++) {
			dfs(grid, i, j);
		}
	}
	return ans;
}
```