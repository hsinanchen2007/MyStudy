### 解题思路
此处撰写解题思路
BSF题，考虑到某个橘子周围感染后将会被再次扫描到, 所以将其置为3, 最后在统一变成2即可
### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int count = 0;
	while (1){
		int end = 1;
		for (int i = 0; i < gridSize; i++){
			for (int j = 0; j < *gridColSize; j++){
				if (grid[i][j] == 0)
					;
				else if (grid[i][j] == 1){
					if ((i < gridSize - 1 && grid[i + 1][j] == 2) || (j < *gridColSize - 1 && grid[i][j + 1] == 2)){
						grid[i][j] = 2; end = 0;
					}					
				}
				else if (grid[i][j] == 2){
					if (i < gridSize - 1 && grid[i + 1][j] == 1){
						grid[i + 1][j] = 3; end = 0;
					}						
					if (j < *gridColSize - 1 && grid[i][j + 1] == 1){
						grid[i][j + 1] = 3; end = 0;
					}						
				}
				else
					grid[i][j] = 2;					
			}			
		}
		if (end)
			break;
		else
			count++;
	}
	for (int i = 0; i < gridSize; i++)
		for (int j = 0; j < *gridColSize; j++)
			if (grid[i][j] == 1)
				return -1;
	return count;

}
```