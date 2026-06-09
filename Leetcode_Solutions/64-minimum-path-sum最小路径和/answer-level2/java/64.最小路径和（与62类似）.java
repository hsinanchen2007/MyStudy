### 解题思路
与62（不同路径）差不多。不同的是递推关系有些改变：
答：DP“老三样”
	1. 建立数组来缓存
	dis[i][j]表示到坐标（i,j）的最小路径距离
	2. 确定递推关系
	62题中，递推关系为：**d[i][j] = d[i][j-1] + d[i-1][j]**
	而这里，我们需要确定最小的那条路，也就是“抄近道过来的”，就需要比较两种走法的大小 即用min比较后，最后加上自己的值
	递推关系为：**dis[i][j] = Math.min(dis[i-1][j], dis[i][j-1]) + grid[i][j]**
	3. 找初始值
	即不满足递推关系的：明显i=0 和 j=0（因为数组下标为负）
	也就是第一行和第一列，进行一个单独的处理

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        if(grid==null) {
			return 0;
		}
		int[][] dis = new int[grid.length][grid[0].length];
		dis[0][0]=grid[0][0];
		//第一行 只有一种走法
		for(int j=1;j<grid[0].length;j++) {
			dis[0][j]=dis[0][j-1]+grid[0][j];
			}
		//第一列 只有一种走法
		for( int i=1;i<grid.length;i++) {
			dis[i][0] = dis[i-1][0] + grid[i][0];
		}
		for(int i=1;i<grid.length;i++) {
			for(int j=1;j<grid[0].length;j++) {
				dis[i][j] = Math.min(dis[i-1][j], dis[i][j-1]) + grid[i][j];
			}
		}
		return dis[grid.length-1][grid[0].length-1];
    }
}
```