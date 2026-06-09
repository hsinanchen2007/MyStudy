### 解题思路
1. 定义一个`count`变量由于计数；
2. 对`m*n`的矩阵进行遍历；
3. 比较矩阵元素与`0`的大小，小于`0`时，`count`加一；
4. 返回`count`即为矩阵中元素小于`0`的个数； 	

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int count = 0;
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				if (grid[i][j] < 0) {
					count += 1;
				}
			}
		}
		return count;
    }
}
```