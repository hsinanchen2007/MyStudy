年轻了，生生解出来的...行列计数不存在的

```
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int result = 0;
		if (n == 0 || m == 0) {
			return 0;
		}
		if (indices.length == 0) {
			return 0;
		}
		int[][] matrix = new int[n][m];
		for (int i = 0; i < indices.length; i++) {
			for (int j = 0; j < m; j++) {
				matrix[indices[i][0]][j] += 1;

			}
			for (int k = 0; k < n; k++) {
				matrix[k][indices[i][1]]++;
			}
		}
		for (int z = 0; z < matrix.length; z++) {
			for (int y = 0; y < matrix[z].length; y++) {
				if (matrix[z][y] % 2 != 0) {
					result++;
				}
			}

		}
		return result;
    }
}
```
