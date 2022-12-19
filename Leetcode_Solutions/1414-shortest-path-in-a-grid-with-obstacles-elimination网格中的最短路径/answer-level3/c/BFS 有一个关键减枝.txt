### 解题思路
有权图，用SPFA，无权BFS
这里BFS标记visit后，如果后边发现step更少，则重新启用当前节点
cur.use < visit[cur.x][cur.y] 这个判断是关键，开始总是超出范围。
考虑一下：
1、如果一直标记visit，则可能错过一个可能的路径
2、一种错过的路径，有一定是cur更少
3、因为考虑一下，如果完全没有障碍物，那么回头路有一定不是最优解

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int x;
	int y;
	int use;
	int step;
};

#define MAX_NODE   4096 * 10
static struct node list[MAX_NODE];
static int list_first;
static int list_last;
static int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

static inline int is_okay(int x, int y, int row, int col)
{
	if (x >= 0 && x < row && y >= 0 && y < col)
		return 1;
	return 0;
}

int shortestPath(int **grid, int gridSize, int *gridColSize, int k)
{
	int loop;
	int new_x;
	int new_y;
	struct node pre = { 0 };
	struct node cur = { 0 };
	if (!grid || gridSize == 0 || *gridColSize == 0) {
        printf("init zero\n");
		return 0;
	}
	int visit[gridSize][*gridColSize];
	memset(visit, 0x0f, sizeof(visit));
	list_first = 0;
	list_last = 0;
	cur.step = 0;
	cur.x = 0;
	cur.y = 0;
	cur.use = 0;
	list[list_first++] = cur;
	while (list_last < list_first)
	{
		pre = list[list_last++];
		if (pre.x == gridSize - 1 && pre.y == *gridColSize - 1)
			return pre.step;
		for (loop = 0; loop < 4; loop++) {
			cur.x = pre.x + dir[loop][0];
			cur.y = pre.y + dir[loop][1];
			cur.step = pre.step + 1;
			cur.use = pre.use;
            		// printf("new %d %d\n", cur.x, cur.y);
			if (is_okay(cur.x, cur.y, gridSize, *gridColSize)) {
                		// printf("okay %d %d\n", cur.x, cur.y);
				if (grid[cur.x][cur.y] == 1) {
					cur.use = pre.use + 1;
				}
				if (cur.use <= k && cur.use < visit[cur.x][cur.y]) {
                    			// printf("add %d %d\n", cur.x, cur.y);
					visit[cur.x][cur.y] = cur.use;
					list[list_first++] = cur;
				}
			}
		}
	}
	return -1;
}
```