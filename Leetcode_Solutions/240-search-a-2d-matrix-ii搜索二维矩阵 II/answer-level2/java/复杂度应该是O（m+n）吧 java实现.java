
public static boolean searchMatrix(int[][] matrix, int target) {

		if (matrix == null) {
			return false;
		}
		int m = matrix.length;
		if (m == 0) {
			return false;
		}
		int n = matrix[0].length;
		int i = 0;
		int j = 0;
		while (i < m && j < n) {
			if (matrix[i][j] > target) {
				i++;
				if (i < m && target > matrix[i][j]) {
					j++;
				} else {
					j = 0;
				}
			} else {
				if (matrix[i][j] == target) {
					return true;
				} else {
					j++;
					if (j == n) {
						i++;
						j = 0;
					}
				}
			}
		}
		return false;
	}