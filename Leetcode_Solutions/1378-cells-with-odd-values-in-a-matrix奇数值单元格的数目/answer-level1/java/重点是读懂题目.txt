### 解题思路
重点是读懂题目

### 代码

```java
class Solution {
    public  int oddCells(int n, int m, int[][] indices) {
    	int[][] matrix =new int[n][m];
    	int row=0,col=0,count=0;
    	for (int i = 0; i < indices.length; i++) {
    			row=indices[i][0];
    			col=indices[i][1];	
    			for (int q = 0; q < m; q++) {
					matrix[row][q]++;
				}
    			for (int p = 0; p < n; p++) {
    				matrix[p][col]++;
				}
		}
    	for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[0].length; j++) {
				if(matrix[i][j]%2!=0)
					count++;	
			}
		}
		return count;
    }
}
```