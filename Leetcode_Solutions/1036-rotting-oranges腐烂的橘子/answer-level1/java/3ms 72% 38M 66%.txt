### 解题思路
我是看了题解写的
### 代码

```java
class Solution {


    public int orangesRotting(int[][] grid) {

        Queue<Integer> queue = new ArrayDeque<>();
        int m = grid.length, n = grid[0].length;
        // 新鲜橘子总数，腐烂分钟数
        int count = 0, round = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    count++;
                else if (grid[i][j] == 2)
                    queue.offer(i * n + j);
            }
        
        while(count > 0 && !queue.isEmpty()) {
			++round;
			int sz = queue.size();
			for (int i = 0; i < sz; ++i) {
				int coordinate = queue.poll();
				int row = coordinate / n;
				int col = coordinate % n;
				// 边界检查
				if (row >= 0 && row < m && col >= 0 && col < n) {
					int top = row - 1;
					if (top >= 0 && grid[top][col] == 1) {
						--count;
						grid[top][col] = 2;
						queue.offer(top * n + col);
					}
					int left = col - 1;
					if (left >= 0 && grid[row][left] == 1) {
						--count;
						grid[row][left] = 2;
						queue.offer(row * n + left);
					}
					int bottom = row + 1;
					if (bottom < m && grid[bottom][col] == 1) {
						--count;
						grid[bottom][col] = 2;
						queue.offer(bottom * n + col);
					}
					int right = col + 1;
					if (right < n && grid[row][right] == 1) {
						--count;
						grid[row][right] = 2;
						queue.offer(row * n + right);
					}
				}
			}
		}
        return count > 0 ? -1 : round;
    }
   
}
```