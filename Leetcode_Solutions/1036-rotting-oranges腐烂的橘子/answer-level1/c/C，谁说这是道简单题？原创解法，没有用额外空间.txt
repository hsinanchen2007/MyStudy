![1.png](https://pic.leetcode-cn.com/6435b365d8ec148a483eea8e5df78eee6024658ffc8c84f7ae53893f57f44b3f-1.png)



### 解题思路
本题的核心思路是：只考虑1、2右面和下面的
如果是0，不管；
如果是1，只要右面和下面有2 ，自己就感染为2；
如果是2，只要右面和下面是1，将其感染为3（目的是让它在本轮内无法感染别人）；
如果是3，将其置为2。
end作为结束的标志。
结束后，再次扫瞄一遍，如果还有未感染的1，就返回-1。
### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
	int count = 0;
	while (1){
		int end = 1;
		for (int i = 0; i < gridSize; i++){
			for (int j = 0; j < *gridColSize; j++){
				if (grid[i][j] == 3)
					grid[i][j] = 2;
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