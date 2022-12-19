### 解题思路
1.按行逆转
2.矩阵转置（沿对角线交换数据）

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int temp;
		int len = matrix.length;
		for (int i = 0;i< len/2; i++) {
			for(int j=0;j <len; j++) {
				temp = matrix[i][j];
				matrix[i][j] = matrix[len-i-1][j];
				matrix[len-i-1][j] = temp;
			}
		}
		for (int i = 1; i < len; i++) {
			for (int j = 0; j < i; j++) {
				temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
    }
}
```