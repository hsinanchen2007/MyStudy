### 解题思路
最难是读题。
读懂以后，思路见下面
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
    	int area= 0;
    	int vOverlap = 0;  //垂直方向重叠
    	int rOverlap = 0;  //横向重叠
    	int cOverlap = 0;  //纵向重叠
    	for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				area+=grid[i][j];         //正方体总个数
				
				if (grid[i][j]>1) {
					vOverlap+=grid[i][j]-1;
				}
				if (j>0) {      
					rOverlap+=Math.min(grid[i][j-1], grid[i][j]);
				}
				if (i>0) {
					cOverlap+=Math.min(grid[i-1][j],grid[i][j]);
				}
			}
		}
		return area*6-(vOverlap+rOverlap+cOverlap)*2;    
    }
}
```