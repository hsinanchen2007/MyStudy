### 解题思路
具体思路看代码注解

### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
        //第一行元素做前缀和
		for(int a = 1;a<grid[0].length;a++) {
			grid[0][a] = grid[0][a-1] + grid[0][a];
		}
		//第一列元素做前缀和
		for(int b = 1;b<grid.length;b++) {
			grid[b][0] = grid[b-1][0] + grid[b][0];
		}
		//剩余元素选择左边和上边元素中较大者做前缀和
		for(int i = 1;i<grid.length;i++) {
			for(int j = 1;j<grid[0].length;j++) {
				grid[i][j] = (grid[i-1][j]>grid[i][j-1] ? grid[i-1][j] : grid[i][j-1]) + grid[i][j];
			}
		}
		//数组矩阵右下角的元素就是最大值，返回它即可
		return grid[grid.length-1][grid[0].length-1];
    }
}
```