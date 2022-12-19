### 解题思路
循环动态规划+辅助一维数组

### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
        if(grid==null || grid.length<=0 ||grid[0].length<=0) 
			return 0;
		int rows=grid.length;
		int cols=grid[0].length;
		int[] maxValue=new int[cols];
		for(int i=0;i<rows;i++) {
			for(int j=0;j<cols;j++) {
				int left=0;
				int up=0;
				if(i>0)
					up=maxValue[j];
				if(j>0)
					left=maxValue[j-1];
				maxValue[j]=Math.max(up, left)+grid[i][j];
			}
		}
		return maxValue[cols-1];
    }
}
```