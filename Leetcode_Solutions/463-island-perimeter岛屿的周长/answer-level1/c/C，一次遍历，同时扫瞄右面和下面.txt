### 解题思路
出现陆地，周长+4;
右面和下面有陆地，周长-2

### 代码

```c
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
	int per = 0;
	for (int i = 0; i < gridSize; i++){
		for (int j = 0; j < *gridColSize; j++){
			if (grid[i][j]){
				per += 4;
				if (i < gridSize - 1 && grid[i + 1][j] == 1)
					per -= 2;
				if (j < *gridColSize - 1 && grid[i][j + 1] == 1)
					per -= 2;
			}
		}
	}
	return per;
}
```