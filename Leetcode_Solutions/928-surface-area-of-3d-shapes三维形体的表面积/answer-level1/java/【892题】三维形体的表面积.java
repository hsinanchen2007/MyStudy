**方法一：按位置累加**
```
class Solution {
    /**
    * 思路：
    * 以自己位置为坐标原点，右手边属于x轴方向，正前方属于y轴方向。
    * (1) 从坐标原点开始，遍历每个位置可以贡献的不重叠面积并叠加。
    * (2) 遍历完成后返回最终叠加面积。
    */
    public int surfaceArea(int[][] grid) {
		// 配合得到遍历到位置的前后左右四个面。
        int[] dr = new int[]{0, 1, 0, -1};
        int[] dc = new int[]{1, 0, -1, 0};
		// 得到 grid 方阵的边长。
        int N = grid.length;
        int ans = 0;
		// 循环遍历每个位置摆放的立方体。
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                if (grid[r][c] > 0) {
					// 有立方体的位置先加上下两个面的面积。
                    ans += 2;
					// 遍历当前位置的前后左右四个面，总面积加上每一面和旁边位置不重叠的面积。
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        int nv = 0;
						// 前后左右位置没有越界的情况下得到该位置的立方体个数。
                        if (0 <= nr && nr < N && 0 <= nc && nc < N){
							nv = grid[nr][nc];
						}
						// 比旁边高就累加高出的面积，低就表示和其它位置重叠。
                        ans += Math.max(grid[r][c] - nv, 0);
                    }
                }
        return ans;
    }
}
```

**方法二：总面积减去重叠面积**
```
class Solution {
    /**
    * 思路：
    * 以自己位置为坐标原点，右手边属于x轴方向，正前方属于y轴方向。
    * (1) 从坐标原点开始，遍历每个位置记录所有立方体个数和重叠总面积。
    * (2) 遍历完成后立方体个数乘以6减去重叠总面积，返回最终叠加面积。
    */
    public int surfaceArea(int[][] grid) {
        int N = grid.length;
        int cubes = 0; // 记录立方体的数量
        int faces = 0; // 记录立方体接触面的数量
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cubes += grid[i][j];
                if (grid[i][j] > 0) {
                    // 叠起来的 v 个立方体有 v-1 个接触面
                    faces += grid[i][j] - 1;
                }
                if (i > 0) {
                    // 当前柱子与右边柱子的接触面数量
                    faces += Math.min(grid[i][j], grid[i-1][j]);
                }
                if (j > 0) {
                    // 当前柱子与前面边柱子的接触面数量
                    faces += Math.min(grid[i][j], grid[i][j-1]);
                }
            }
        }
        return 6 * cubes - 2 * faces;
    }
}
```
