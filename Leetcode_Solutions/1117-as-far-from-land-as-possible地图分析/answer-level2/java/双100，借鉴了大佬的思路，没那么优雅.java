```
class Solution {
	public int maxDistance(int[][] grid) {

		//辅助数据结构，点
		class Point {
			public int x;
			public int y;

			public Point(int x, int y) {
				this.x = x;
				this.y = y;
			}

		}

		Point[] land = new Point[grid.length * grid.length];
		int landcnt = 0;
		//扫描陆地
		for (int x = 0; x < grid.length; x++) {
			for (int y = 0; y < grid.length; y++) {
				if (grid[x][y] == 1) {
					land[landcnt] = new Point(x, y);
					landcnt++;
				}
			}
		}

		if (landcnt == grid.length * grid.length || landcnt == 0) {
			return -1;
		} else {
			int cursor = 0, dis = 0, changesea = 0;
			for (; cursor < landcnt; cursor++) {
				if (land[cursor].x - 1 >= 0) {
					if (grid[land[cursor].x - 1][land[cursor].y] == 0) {
						land[landcnt + changesea] = new Point(land[cursor].x - 1, land[cursor].y);
						//填海造陆，染色标记
						grid[land[cursor].x - 1][land[cursor].y] = 1;
						changesea++;
					}
				}
				if (land[cursor].x + 1 < grid.length) {
					if (grid[land[cursor].x + 1][land[cursor].y] == 0) {
						land[landcnt + changesea] = new Point(land[cursor].x + 1, land[cursor].y);
						grid[land[cursor].x + 1][land[cursor].y] = 1;
						changesea++;
					}
				}
				if (land[cursor].y - 1 >= 0) {
					if (grid[land[cursor].x][land[cursor].y - 1] == 0) {
						land[landcnt + changesea] = new Point(land[cursor].x, land[cursor].y - 1);
						grid[land[cursor].x][land[cursor].y - 1] = 1;
						changesea++;
					}
				}
				if (land[cursor].y + 1 < grid.length) {
					if (grid[land[cursor].x][land[cursor].y + 1] == 0) {
						land[landcnt + changesea] = new Point(land[cursor].x, land[cursor].y + 1);
						grid[land[cursor].x][land[cursor].y + 1] = 1;
						changesea++;
					}
				}
				if (cursor == landcnt - 1) {
					//之前扫描的陆地曼哈顿距离为1的海已经全部造完
					dis++;
					if (landcnt + changesea == grid.length * grid.length) {
						return dis;
					} else {
						//循环从当前游标继续进行
						landcnt += changesea;
						changesea = 0;
					}
				}

			}
			return dis;
		}

	}

	public static void main(String[] args) {
		//TEST CASE
		int[][] grid = { { 1, 0, 1 }, { 0, 0, 0 }, { 1, 0, 1 } };
		Solution s = new Solution();
		System.out.println(s.maxDistance(grid));
	}
}
```
