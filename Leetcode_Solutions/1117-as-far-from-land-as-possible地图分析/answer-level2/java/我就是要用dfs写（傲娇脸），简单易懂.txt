### 解题思路
1.改变代表海洋和岛屿的数字（这个是关键），因为初始的数字要无意义，才能使得搜索的过程中不会引起歧义。
2.用grid数组中表示海洋的格子中存储上一次搜索时的最优解。

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
		int max = 0;
		for(int i = 0;i<grid.length;i++) {//把岛和海洋的数值现在原数组上改变
			for(int j = 0;j<grid.length;j++) {
				if(grid[i][j]==1)
					grid[i][j]= 0;
				else
					grid[i][j]= -1;
			}
		}
		for(int i = 0;i<grid.length;i++) {//找到岛屿我就从这个岛屿开始搜索
			for(int j = 0;j<grid.length;j++) {
				if(grid[i][j]==0)
					rebuilt(i,j,grid);
			}
		}
		for(int i = 0;i<grid.length;i++) {//找出最大值
			for(int j = 0;j<grid.length;j++) {
				max=max<grid[i][j]?grid[i][j]:max;
			}
		}
		return max==0?-1:max;
    }
	private void rebuilt(int i, int j,int[][] grid) {//用来更新邻点的数值
		if((j+1<grid.length)&&(grid[i][j+1]>grid[i][j]+1||grid[i][j+1]==-1)) {
			grid[i][j+1] = grid[i][j]+1;
			rebuilt(i, j+1, grid);
		}
		if((j-1>=0)&&(grid[i][j-1]>grid[i][j]+1||grid[i][j-1]==-1)) {
			grid[i][j-1] = grid[i][j]+1;
			rebuilt(i, j-1, grid);
		}
		if((i+1<grid.length)&&(grid[i+1][j]>grid[i][j]+1||grid[i+1][j]==-1)) {
			grid[i+1][j] = grid[i][j]+1;
			rebuilt(i+1, j, grid);
		}
		if((i-1>=0)&&(grid[i-1][j]>grid[i][j]+1||grid[i-1][j]==-1)) {
			grid[i-1][j] = grid[i][j]+1;
			rebuilt(i-1, j, grid);
		}
}
}
```