### 解题思路
多源广度优先，思路清晰

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {

        // 多源广度优先
        int m = grid.length, n = grid[0].length;
        Queue<Integer> q = new ArrayDeque<>();
        int count = 0, dis = -1;
        // 将所有源点作为第一层
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++count;
                    q.offer(i * n + j);
                }
            }

        if (count == 0 || count == m * n) return -1;
        while (!q.isEmpty()) {
			++dis;
			for (int i = 0, sz = q.size(); i < sz; ++i) {
				int val = q.poll();
				int row = val / n, col = val % n;
				if (row >= 0 && row < m && col >= 0 && col < n) {
					int top = row - 1, bot = row + 1;
					if (top >= 0 && grid[top][col] == 0) {
						grid[top][col] = 1;
						q.offer(top * n + col);
					}
					if (bot < m && grid[bot][col] == 0) {
						grid[bot][col] = 1;
						q.offer(bot * n + col);
					}
					int left = col - 1, right = col + 1;
					if (left >= 0 && grid[row][left] == 0) {
						grid[row][left] = 1;
						q.offer(row * n + left);
					}
					if (right < n && grid[row][right] == 0) {
						grid[row][right] = 1;
						q.offer(row * n + right);
					}
				}
			}
		}

        return dis;
    }
}
```