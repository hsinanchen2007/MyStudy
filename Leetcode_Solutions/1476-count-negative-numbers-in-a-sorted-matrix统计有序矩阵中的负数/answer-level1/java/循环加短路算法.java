### 解题思路
在最左端的负数处“短路”break;
### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int m = grid.length;
		int n = grid[0].length;
		int r = 0;// result
		int p = n;// p 指本行要检查的最多列数
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p; j++) {
				if (grid[i][j] < 0) {// 找到本行最左端的负数
					r += (n - j);// 本行余下的负数个数
					p = j + 1;
					break;
				}
			}
		}
		return r;
    }
}
```