### 解题思路
	因为BFS要用到队列，C语言内置没有队列，这里通过一个二维数组来实现队列的管理
	要输出BFS的层数，所以需要维持一个记录当前队尾指针的变量，用来判断是否已经完成当次遍历
	最后判断是否有橘子不会被腐烂，全局记录一个未腐烂橘子数，BFS完后判断该数是否大于0即可。
	切记：全局变量必须严格初始化！不然会执行结果和提交结果可能不一致！

### 代码

```c
int distance[4][2] = { {0,1},{0,-1},{1,0},{-1,0}};
int times = 0;
int normalOrange = 0;
void BFS(int queue[][2], int front, int rear, int** grid, int gridSize, int* gridColSize) {
	int pos = rear;
	while (rear - front) {
		// record rear point everytime
		if (front == pos) {
			times++;
			pos = rear;
		}
		int i = queue[front][0];
		int j = queue[front][1];
		front++;
		if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize) {
			return;
		}
		for (int k = 0; k < 4; ++k) {
			if (i + distance[k][0] < 0 || i + distance[k][0] >= gridSize || j + distance[k][1] < 0 || j + distance[k][1] >= *gridColSize) {
				continue;
			}
			if (grid[i + distance[k][0]][j + distance[k][1]] == 1) {
				grid[i + distance[k][0]][j + distance[k][1]] = 2;
				normalOrange--;
				queue[rear][0] = i + distance[k][0];
				queue[rear][1] = j + distance[k][1];
				rear++;
			}
		}
	}
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
	if (grid == NULL || gridSize == 0 || *gridColSize == 0) {
		return -1;
	}
    normalOrange = 0;
    times = 0;
	int queue[150][2];
	memset(queue, 0, sizeof(int) * 150);
	int front = 0;
	int colSize = *gridColSize;
	int rear = 0;
	for (int i = 0; i < gridSize; ++i) {
		for (int j = 0; j < *gridColSize; ++j) {
			if (grid[i][j] == 2) {
				queue[rear][0] = i;
				queue[rear][1] = j;
				rear++;
			}
			if (grid[i][j] == 1) {
				normalOrange++;
			}
		}
	}
	BFS(queue, front, rear, grid, gridSize, gridColSize);
    if (normalOrange > 0) {
		return -1;
	}
	return times;
}
```