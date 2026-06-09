### 解题思路
执行结果：
通过
显示详情
执行用时 :1 ms, 在所有 Java 提交中击败了99.96%的用户
内存消耗 :41.8 MB, 在所有 Java 提交中击败了98.01%的用户
第三中方法。
### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
       int R = matrix.length;
		int C = matrix[0].length;
		
		boolean row = false;
        boolean col = false;
        
		boolean flag = false;
		for(int i = 0;i < R;i++) {
			for(int j = 0;j < C;j++) {
				
				if(i == 0 && j == 0 && matrix[i][j] == 0) {
					flag = true;
				}
				else if(matrix[i][j] == 0) {
					if(i == 0) {
						row = true;
					}else if(j == 0) {
						col = true;
					}
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for(int i = 1;i < R;i++) 
			if(matrix[i][0] == 0)
			for(int j = 0;j < C;j++)matrix[i][j] = 0;
		
		for(int i = 1;i < C;i++) 
			if(matrix[0][i] == 0)
			for(int j = 0;j < R;j++)matrix[j][i] = 0;
		if(row)
			for(int i = 0;i < C;i++)matrix[0][i] = 0;
		
		if(col)
			for(int i = 0;i < R;i++)matrix[i][0] = 0;
		
		if(flag) {
			for(int i = 1;i < C;i++) matrix[0][i] = 0;
			for(int i = 1;i < R;i++) matrix[i][0] = 0;
		}
    }
}
```