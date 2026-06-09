```
public List<Integer> spiralOrder(int[][] matrix) {
		List<Integer> list = new ArrayList<>();
		int m = matrix.length;
		if (m == 0) {
			return list;
		}
		int n = matrix[0].length;
		doHelper(matrix, list, m, n, 0);
		return list;

	}

	/**
	 * 一圈圈遍历就好了，按照规则，，，，
	 * 
	 * @param matrix
	 * @param list
	 * @param m
	 * @param n
	 * @param times
	 */
	public void doHelper(int[][] matrix, List<Integer> list, int m, int n, int times) {
		if (times * 2 >= n || times * 2 >= m)
			return;
		/**
		 * 先遍历上边
		 */
		for (int i = times; i < n - times; i++) {
			list.add(matrix[times][i]);
		}
		/**
		 * 再遍历右边
		 */
		for (int i = times + 1; i < m - times; i++) {
			list.add(matrix[i][n - times - 1]);
		}

		if ((m - 2 * times) > 1)
			/**
			 * 再遍历下边
			 */
			for (int i = n - times - 2; i >= times; i--) {
			list.add(matrix[m - times - 1][i]);
			}

		if ((n - 2 * times) > 1)

			/**
			 * 再遍历左边
			 */
			for (int i = m - times - 2; i >= times + 1; i--) {
			list.add(matrix[i][times]);
			}

		doHelper(matrix, list, m, n, times + 1);

	}
```
