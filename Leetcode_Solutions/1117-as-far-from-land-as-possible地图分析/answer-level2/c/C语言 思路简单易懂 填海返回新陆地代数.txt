### 解题思路
模拟填海，从新一代陆地将周围距离为1的海洋填成陆地，最后返回填海产生的代数k == 2 ? -1 : k - 2

### 代码

```c
int maxDistance(int** grid, int gridSize, int* gridColSize){
    int k = 2; // 填海代数
	int flag = 0;
	do {
		flag = 0;
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < *gridColSize; j++) {
				if (grid[i][j] == (k - 1)) {
					// 上
					if (i > 0 && grid[i - 1][j] == 0) {
						grid[i - 1][j] = k;
						flag = 1;
					}
					// 下
					if (i < gridSize - 1 && grid[i + 1][j] == 0) {
						grid[i + 1][j] = k;
						flag = 1;
					}
					// 左
					if (j > 0 && grid[i][j - 1] == 0) {
						grid[i][j - 1] = k;
						flag = 1;
					}
					// 右
					if (j < *gridColSize - 1 && grid[i][j + 1] == 0) {
						grid[i][j + 1] = k;
						flag = 1;
					}
				}
			}
		}
		if (flag) {
			k++;
		}
	} while (flag);
	return	k == 2 ? -1 : k - 2;
}
```