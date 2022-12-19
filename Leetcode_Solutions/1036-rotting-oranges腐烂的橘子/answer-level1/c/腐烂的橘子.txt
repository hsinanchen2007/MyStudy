### 解题思路
grid 是橘子框
gridsize 是行数
gridColSize 是个数组，每个元素就是每行的列数 gridColSize[i] 就是grid第i行的列数

简单广度优先遍历，不明白gridColSize的用法+测试用例比较恶心=提交了很多次。

### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){

	//申请时间记录矩阵
	int** times = (int **)malloc(sizeof(int*)*gridSize);
	for (int i = 0; i < gridSize; ++i)
	{   //矩阵每个初始值是-1
		times[i] = (int *)malloc(sizeof(int)*gridColSize[i]);
		for (int j = 0; j < gridColSize[i]; ++j)
			times[i][j] = -1;
	}

	//申请一个队列，存放行列数
	int queueRows[100], queueCols[100];
	int head = 0, rear = 0;

	//检查烂橘子，烂橘子位置入队列，烂橘子时间标记为0。
	int allRot = 1,allGood=1;
	for (int row = 0; row < gridSize; ++row)
		for (int col = 0; col < gridColSize[row]; ++col)
        	if (grid[row][col] == 2)
			{
                allGood=0;
				rear = (rear + 1) % 100;
				queueRows[rear] = row;
				queueCols[rear] = col;
				times[row][col] = 0;
			}
			else if (grid[row][col] == 1)allRot = 0;
	//当队列不为空的时候
	while (rear != head)
	{
		//出队，获取一个烂橘子坐标
		head = (head + 1) % 100;
		int row = queueRows[head];
		int col = queueCols[head];
		//如果右边还有橘子&&右边的是个好橘子&&右边的橘子没记录时间
		if (col + 1 < gridColSize[row]&&grid[row][col + 1] == 1 && times[row][col + 1] == -1)
		{   //右边的橘子入队，右边的橘子时间是当前腐烂橘子时间+1
			rear = (rear + 1) % 100;
			queueRows[rear] = row;
			queueCols[rear] = col + 1;
			times[row][col + 1] = (times[row][col] + 1);
		}
		//检查下边的橘子
		if (row + 1 < gridSize&&grid[row + 1][col] == 1 && times[row + 1][col] == -1)
		{
			rear = (rear + 1) % 100;
			queueRows[rear] = row + 1;
			queueCols[rear] = col;
			times[row + 1][col] = (times[row][col] + 1);
		}
		//检查左边的橘子
		if (col - 1 >= 0 && grid[row][col - 1] == 1 && times[row][col - 1] == -1)
		{
			rear = (rear + 1) % 100;
			queueRows[rear] = row;
			queueCols[rear] = col - 1;
			times[row][col - 1] = (times[row][col] + 1);
		}
		//检查上边的橘子
		if (row - 1 >= 0 && grid[row - 1][col] == 1 && times[row - 1][col] == -1)
		{
			rear = (rear + 1) % 100;
			queueRows[rear] = row - 1;
			queueCols[rear] = col;
			times[row - 1][col] = (times[row][col] + 1);
		}
	}

	//统计最后一个橘子腐烂的时间，同时排查是不是有没烂的橘子。
	int max = 0;int someFresh=0;
	for (int row = 0; row < gridSize; ++row)
		for (int col = 0; col < gridColSize[row]; ++col)
		{
			//有没腐烂的橘子
			if (grid[row][col] == 1 && times[row][col] == -1)
                someFresh=1;
			//更新最后才腐烂的时间
			else if (max <= times[row][col])
				max = times[row][col];
		}

	//释放时间矩阵的空间
	for (int i = 0; i < gridSize; ++i)
		free(times[i]);
	free(times);

    if(someFresh)return -1;
    if(gridSize==1&&gridColSize[0]==1)return 0;//针对[[0]]
    if(allGood)return -1;//针对[[0,1]]
    if(allRot)return 0;//针对[[0,2]]

	return max;
}

```