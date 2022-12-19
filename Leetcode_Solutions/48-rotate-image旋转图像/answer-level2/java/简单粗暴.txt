### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
		int ROW = matrix.length;
		int COLUMN = matrix[0].length;
		boolean[][] flag = new boolean[ROW][COLUMN];
		for (int i = 0; i <= COLUMN - 1; i++) {
			for (int j = ROW - 1; j >= 0; j--) {
				if (!flag[ROW - j - 1][i]) {
					// 交换matrix[i][j]和matrix[ROW - j - 1][i]位置
					int swap = matrix[i][j];
					matrix[i][j] = matrix[ROW - j - 1][i];
					matrix[ROW - j - 1][i] = swap;
					//做标记
					flag[i][j] = true;
					flag[ROW - j - 1][i] = true;
				}
			}
		}
	}
}
```