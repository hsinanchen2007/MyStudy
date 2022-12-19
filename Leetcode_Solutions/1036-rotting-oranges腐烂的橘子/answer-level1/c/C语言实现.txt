### 解题思路
将每分钟被感染的节点找出（利用变量k，确定感染批次），直到不再有新的感染发生，遍历最后结果，存在新鲜橘子返回-1，否则返回所用时间。

### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int k = 3;
	int res = 0;
	int flag = 0;
	while (flag == 0) {
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < *gridColSize; j++) {
				if (grid[i][j] == 1) {	
					if (i != 0 && grid[i - 1][j] > 1 && grid[i - 1][j] < k) {
						// up
						grid[i][j] = k;
						flag = 1;
					} else if (i < gridSize - 1 && grid[i + 1][j] > 1 && grid[i + 1][j] < k) {
						// down
						grid[i][j] = k;
						flag = 1;
					} else if (j != 0 && grid[i][j - 1] > 1 && grid[i][j - 1] < k) {
						// left
						grid[i][j] = k;
						flag = 1;
					} else if (j < *gridColSize - 1 && grid[i][j + 1] > 1 && grid[i][j + 1] < k) {
						// right
						grid[i][j] = k;
						flag = 1;
					}
				}
			}
		}
		if (flag) {
			k++;
			flag = 0;
		} else {
			break;
		}
	}
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == 1) {
				return -1;
			}
		}
	}
	res = k - 3;
	return res;
}
```