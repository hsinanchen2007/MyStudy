### 解题思路
和求岛屿面积的解法类似，
区别：

1. 这是求count，所以在最外层循环才更新count，内部经过多少面积没关系。
2. 因为有/和\，随意可能一个i，j会更新2次，随意按照 &1 和 &2 来看是更新一次还是2次
### 代码

```java
class Solution {
   public int regionsBySlashes(String[] grid) {

		int[][] tmp = new int[grid.length][];
		for (int i = 0; i < tmp.length; i++) {
			tmp[i] = new int[grid.length];
		}

		int rst = 0;
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid.length; j++) {
				int t = search(i, j, tmp, grid, 0);
				if((t&1)>0)
					rst++;
				if((t&2)>0)
					rst++;
			}
		}

		return rst;
	}

	private int search(int i, int j, int[][] tmp, String[] grid, int direct/* 0,1,2,3,4 */) {
		if (i < 0 || i >= grid.length || j < 0 || j >= grid.length) {
			return 0;
		}

		int rst = 0;
		if (grid[i].charAt(j) == ' ') {
			if (tmp[i][j] == 0) {
				// 上下左右
				tmp[i][j] = 1;
				search(i - 1, j, tmp, grid, 1);
				search(i + 1, j, tmp, grid, 3);
				search(i, j - 1, tmp, grid, 4);
				search(i, j + 1, tmp, grid, 2);
				rst = 1;
//				System.out.println(i+" "+j);
			}
		} else if (grid[i].charAt(j) == '/') {
			if ((tmp[i][j] & 1) == 0 && (direct == 1 || direct == 4|| direct == 0)) {
				// 下右
				tmp[i][j] |= 1;
				if (direct == 4 || direct ==0)
					search(i + 1, j, tmp, grid, 3);
				if (direct == 1|| direct ==0)
					search(i, j + 1, tmp, grid, 2);
				rst |=1;
//				System.out.println(i+" "+j);
			}
			if ((tmp[i][j] & 2) == 0 && (direct == 2 || direct == 3|| direct ==0)) {
				// 上左
				tmp[i][j] |= 2;
				if (direct == 2|| direct ==0)
					search(i - 1, j, tmp, grid, 1);
				if (direct == 3|| direct ==0)
					search(i, j - 1, tmp, grid, 4);
				rst |=2;
//				System.out.println(i+" "+j);
			}
		} else if (grid[i].charAt(j) == '\\') {
			if ((tmp[i][j] & 1) == 0 && (direct == 3 || direct == 4|| direct ==0)) {
				// 上右
				tmp[i][j] |= 1;
				if (direct == 4|| direct ==0)
					search(i - 1, j, tmp, grid, 1);
				if (direct == 3|| direct ==0)
					search(i, j + 1, tmp, grid, 2);
				rst |=1;
//				System.out.println(i+" "+j);
			}
			if ((tmp[i][j] & 2) == 0 && (direct == 2 || direct == 1|| direct ==0)) {
				// 下左
				tmp[i][j] |= 2;
				if (direct == 2|| direct ==0)
					search(i + 1, j, tmp, grid, 3);
				if (direct == 1|| direct ==0)
					search(i, j - 1, tmp, grid, 4);
				rst |=2;
//				System.out.println(i+" "+j);
			}
		}
		return rst;
	}
}
```