### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/040b0b8f3d7233c1e818547bb5c613ea1a7d2aa02eb07ede8679e757e3eaafc1-%E6%8D%95%E8%8E%B7.PNG)

主要思想:
boolean[][] flags = new boolean[ROW][COLUMN]; //记录有没有被更新过
boolean[][] originZeroflags = new boolean[ROW][COLUMN]; // 在更新过程中保留原来就为0的下标元素


### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
		int ROW = matrix.length;
		if (ROW == 0) {
			return;
		}
		int COLUMN = matrix[0].length;
		if (COLUMN == 0) {
			return;
		}
		boolean[][] flags = new boolean[ROW][COLUMN];
		boolean[][] originZeroflags = new boolean[ROW][COLUMN];
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COLUMN; j++) {
				if ((matrix[i][j] == 0 && !flags[i][j]) || originZeroflags[i][j]) {
					flags[i][j] = true;
					for (int index = 0; index < COLUMN; index++) {
						if (index != j && matrix[i][index] == 0 && !flags[i][index]) {
							originZeroflags[i][index] = true;
						}
						matrix[i][index] = 0;
						flags[i][index] = true;
					}
					for (int index = 0; index < ROW; index++) {
						if (index != i && matrix[index][j] == 0 && !flags[index][j]) {
							originZeroflags[index][j] = true;
						}
						matrix[index][j] = 0;
						flags[index][j] = true;
					}
				}
			}
		}

	}
}
```