	class Solution {
		public void rotate(int[][] matrix) {
			int row = matrix.length;
			int col = matrix[0].length;
			for(int i = 0,j = 0;i<=(row-1)/2 && j<=(col-1)/2;i++,j++) {
				int k = j;
				for(;k < col-j-1;k++) {
					swap(matrix,i,k,k,col-j-1);
					swap(matrix,i,k,row-i-1,col-k-1);
					swap(matrix,i,k,row-k-1,j);
				}
			}
		}
		public void swap(int[][] matrix, int i, int j, int x, int y) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[x][y];
			matrix[x][y] = temp;
		}
	}