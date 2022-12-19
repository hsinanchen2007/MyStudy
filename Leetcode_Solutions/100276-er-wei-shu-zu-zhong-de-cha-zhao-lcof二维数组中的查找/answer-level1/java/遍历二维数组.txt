### 解题思路
遍历二维数组

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
    	for (int i = 0; i < matrix.length; i++) {
    		for (int j = 0; j < matrix[i].length; j++) {
				if (target==matrix[i][j]) {
					return true;
				}
			}
			
		}
    	return false;
    	
    }
}
```