### 解题思路
分x y z三个方向，z比较容易，有就+2
x和y采用台阶，本级和上级差的绝对值即是一个面的面积，关键是最后一个面，其实最后一个有多少个就有多少的面积，因为已经到了边缘
![image.png](https://pic.leetcode-cn.com/0f7941418ec9e675674ed9d1c04cff2fcb3d2d5e7822c62004951f219d4eea58-image.png)

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
	int i, j, pre;
	int x, y, z;
	x = 0;
	for (i = 0; i < gridSize; i++) {
		pre = 0;
		for (j = 0; j < gridColSize[0]; j++) {
			x += abs(grid[i][j] - pre);
			pre = grid[i][j];
		}
		x += pre;
	}
	y = 0;
	for (i = 0; i < gridColSize[0]; i++) {
		pre = 0;
		for (j = 0; j < gridSize; j++) {
			y += abs(grid[j][i] - pre);
			pre = grid[j][i];
		}
		y += pre;
	}
	z = 0;
	for (i = 0; i < gridSize; i++) {
		for (j = 0; j < gridColSize[0]; j++) {
			if (grid[i][j] != 0) {
				z += 2;
			}
		}
	}
	return x + y + z;
}
```