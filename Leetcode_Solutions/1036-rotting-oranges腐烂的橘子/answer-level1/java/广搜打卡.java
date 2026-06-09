### 解题思路
- 时间复杂度：O(m × n)
- 空间复杂度：O(m × n)
- 思路：先将腐败的橘子加进队列中，同时清除标记，初始时腐烂的橘子处时间为0，每次只往新鲜的橘子位置处走即可。有个技巧，如何存储坐标点的位置，把二维数组堪称一维数组来处理即可！
- 另外：ArrayDeque是JDK容器中的一个双端队列实现，内部使用数组进行元素存储，不允许存储null值，可以高效的进行元素查找和尾部插入取出，是用作队列、双端队列、栈的绝佳选择，性能比LinkedList还要好。

### 代码

```java
class Solution {
	private int dir[][] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
	private int m, n;

	public int orangesRotting(int[][] grid) {
		if (grid == null || (m = grid.length) == 0 || (n = grid[0].length) == 0)
			return 0;
		Queue<Integer> queue = new ArrayDeque<Integer>();
		int[][] dis = new int[m][n];// 申请一个数组来保存经过的时间
		int cnt1 = 0; // 标记新鲜橘子的个数
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 2) { // 把所有已腐烂的橘子先添加到队列中
					queue.add(i * n + j);
					grid[i][j] = 0;// 并将其修改为空单元格。
				} else if (grid[i][j] == 1)
					cnt1++;
			}
		}
		int cur, x, y, dx, dy, res = 0; // 初始值为0
		while (cnt1 > 0 && !queue.isEmpty()) {
			cur = queue.remove();
			x = cur / n;
			y = cur % n;
			for (int i = 0; i < 4; i++) {
				dx = x + dir[i][0];
				dy = y + dir[i][1];
				if (check(dx, dy) && grid[dx][dy] == 1) { // 若是新鲜橘子
					dis[dx][dy] = dis[x][y] + 1;
					queue.add(dx * n + dy);
					grid[dx][dy] = 0; // 将其变为空单元格
					res = dis[dx][dy]; // 因为是按层遍历的，最后走到一个新鲜的橘子时间是肯定是最长的。
					cnt1--;
				}
			}
		}
		return cnt1 > 0 ? -1 : res;
	}

	private boolean check(int x, int y) {
		return x >= 0 && x < m && y >= 0 && y < n;
	}
}
```