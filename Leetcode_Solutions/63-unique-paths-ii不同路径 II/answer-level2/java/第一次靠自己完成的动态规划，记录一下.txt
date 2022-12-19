### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    if(obstacleGrid.length==0)
    	return 0;
    if(obstacleGrid[0][0]==1)
    	return 0;
    else {
    	int [][] t = new int[obstacleGrid.length][obstacleGrid[0].length];
    	t[0][0]=1;
    	for(int i=0;i<obstacleGrid.length;i++)
    		for(int j=0;j<obstacleGrid[0].length;j++) {
    			if(i==0&&j==0||obstacleGrid[i][j]==1)
    				continue;
    			if(i!=0&&j==0)
    				t[i][j]=t[i-1][j];
    			else if(i==0&&j!=0)
    				t[i][j]=t[i][j-1];
    			else {
    				t[i][j]=t[i-1][j]+t[i][j-1];
    			}
    		}
    	return t[t.length-1][t[0].length-1];
    }
    }
}
```