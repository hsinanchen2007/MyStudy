## 执行
```
执行用时 : 5 ms, 在Surface Area of 3D Shapes的Java提交中击败了95.95% 的用户
内存消耗 : 35.8 MB, 在Surface Area of 3D Shapes的Java提交中击败了100.00% 的用户
```

## 思路
首先理解题意，N*N的二维数组中的每个值代表着这个位置上有几个立方体，例如，[[2]]代表1*1上坐标(0,0)的位置上有2个立方体，[[1,2],[3,4]]则代表着坐标(0,0)(0,1)(1,0)(1,1)上分别有1,2,3,4个立方体，以此类推。

1. 三维形体的表面积=每个位置上组合立方体的表面积-每个位置上组合立方体的邻接面积。
2. 用两个数记录每个位置上组合立方体的表面积和每个位置上组合立方体的邻接面积。
3. 组合立方体的表面积求和公式为立方体个数*4+2；邻接面积则为邻接面个数*2。
4. 遍历二维数组，当值不为0时记录组合立方体的表面积，并且记录 i 行与 i + 1 行的邻接面积， i 列与 i + 1 列的邻接面积。
5. 返回三维形体的表面积

## 实现
```
class Solution {
    public int surfaceArea(int[][] grid) {
	int length = grid.length;
	int surface1 = 0;    //记录每个位置上组合立方体的表面积
	int surface2 = 0;    //记录每个位置上组合立方体的邻接面积
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (grid[i][j] != 0) {
				surface1 += grid[i][j] * 4 + 2;    //记录当前位置上组合立方体的表面积
			}
			if (i != length - 1) {
				surface2 += (grid[i][j] > grid[i + 1][j] ? grid[i + 1][j] : grid[i][j]) * 2;    //记录 i 行与 i + 1 行的邻接面积
				surface2 += (grid[j][i] > grid[j][i + 1] ? grid[j][i + 1] : grid[j][i]) * 2;    //记录 i 列与 i + 1 列的邻接面积
			}
		}
	}
	return surface1 - surface2;
    }
}
```