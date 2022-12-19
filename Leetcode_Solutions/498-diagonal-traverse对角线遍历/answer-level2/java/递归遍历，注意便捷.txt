### 解题思路
递归遍历，但是要注意边界

O(m*n) ~ 2ms

O((m+n-1) * (m+n-1)) ~ 250ms

![image.png](https://pic.leetcode-cn.com/0f6321e72917f1d1b0245be35d28e3a32268804df37fb9af1fd744d1e25262b8-image.png)


### 代码

```java
class Solution {
     public int[] findDiagonalOrder(int[][] matrix) {

		if (matrix.length == 0)
			return new int[] {};
		int[] r = new int[matrix.length * matrix[0].length];

		int id = 0;
		;

		int i = 0;
		boolean up = true;
		find(id, i, r, up, matrix);
		return r;
	}

	private void find(int id, int i, int[] r, boolean up, int[][] matrix) {

		if (id == (matrix.length + matrix[0].length - 1))
			return;

		int j;
		if (up)
			j = id > matrix.length - 1 ?  matrix.length -1 : id;
		else
			j = id > matrix[0].length - 1 ? matrix[0].length - 1 : id;
		for (; j >=0; j--) {
			int k = id - j;
			if ((up && j < matrix.length && k < matrix[0].length)
					|| (!up && k< matrix.length && j < matrix[0].length)) {
				r[i++] = up ? matrix[j][k] : matrix[k][j];
			} else {
				break;
			}

		}
		find(++id, i, r, !up, matrix);
	}

}
```