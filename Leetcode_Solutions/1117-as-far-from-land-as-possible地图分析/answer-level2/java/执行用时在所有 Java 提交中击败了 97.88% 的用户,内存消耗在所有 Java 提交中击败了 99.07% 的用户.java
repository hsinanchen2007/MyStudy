### 解题思路
表示距离：用负数表示该海洋区离陆地的最远距离（因为1是陆地避免混淆）
思想：从陆地开始不断向四周扩散

遍历第一遍：求和，如果和是0或者是N*N，返回-1
遍历第二遍：找陆地，每个陆地的上下左右的海洋都要变成-1 
循环不断遍历：
每个上一轮找到过的海洋的上下左右的0都赋值为上一轮的距离再-1
直到没有0的海洋退出循环
遍历最后一遍：找出最小的数，返回这个数的相反数

### 代码

```java
class Solution {
	int[][] grid;
	int N;
    public int maxDistance(int[][] grid) {
    	boolean end = false;
    	int distance = -1;
    	int res = 0;
    	int sum = 0;
    	this.grid = grid;
    	N = grid.length;
    	for(int i = 0;i<N;i++) {
    		for(int j = 0;j<N;j++) {
    			sum += grid[i][j];
    		}
    	}
    
    	if(sum == 0 || sum == N*N) return -1;
    	for(int i = 0;i<N;i++) {
    		for(int j = 0;j<N;j++) {
    			if(grid[i][j] == 1) {
    				if(i>0 && grid[i-1][j]==0) grid[i-1][j] = -1;
    				if(j>0 && grid[i][j-1]==0) grid[i][j-1] = -1;
    				if(i<N-1 && grid[i+1][j]==0) grid[i+1][j] = -1;
    				if(j<N-1 && grid[i][j+1]==0) grid[i][j+1] = -1;
    			}
    		}
    	}
    	
    	while(!end) {
    		end = findIsland(distance);
    		distance--;
    	}
    	
    	for(int i = 0;i<N;i++) {
    		for(int j = 0;j<N;j++) {
    			res = Math.min(res,grid[i][j]);
    		}
    	}
    	return -res;
    }
    private boolean findIsland(int distance) {
    	boolean end = true;
		for(int i = 0;i<N;i++) {
    		for(int j = 0;j<N;j++) {
    			if(grid[i][j] == distance) {
    				end = false;
    				if(i>0 && grid[i-1][j]==0) grid[i-1][j] = distance-1;
    				if(j>0 && grid[i][j-1]==0) grid[i][j-1] = distance-1;
    				if(i<N-1 && grid[i+1][j]==0) grid[i+1][j] = distance-1;
    				if(j<N-1 && grid[i][j+1]==0) grid[i][j+1] = distance-1;
    			}
    		}
    	}
		return end;
	}
}
```