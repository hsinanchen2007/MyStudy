```
class Solution {

    public int maxIncreaseKeepingSkyline(int[][] grid) {
       int length = grid[0].length;
		
		int []col = new int[length];
		int []row = new int[length];
		
		// 1.找出天际线
		for (int i=0; i<length; i++){
			int []tempCol = new int[length];
			int []tempRow = new int[length];
			for (int j=0; j<length; j++){
				tempCol[j] = grid[j][i];
				tempRow[j] = grid[i][j];
			}
			
			Arrays.sort(tempCol);
			Arrays.sort(tempRow);
			
			col[i] = tempCol[length-1];
			row[i] = tempRow[length-1];
		}
		
		// 2.针对某个元素，增加到和行和列最小的一个值
		int sum=0;
		for(int i=0; i<length; i++){

			for (int j=0; j<length; j++){
				
				// i行j列
				int rowMax = row[i];
				int rowCol = col[j];
				
				sum += (Math.min(rowCol, rowMax) - grid[i][j]);
				
			}
		}
		
		return sum;

    }
}
```