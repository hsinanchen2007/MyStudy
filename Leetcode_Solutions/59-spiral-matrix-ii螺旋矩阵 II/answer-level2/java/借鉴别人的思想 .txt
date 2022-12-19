按外圈到内圈进行赋值
```
public int[][] generateMatrix(int n) {

		int result[][]=new int[n][n];
		int top=0,bottom=n-1;
		int left=0,right=n-1;
		int max=n*n;
		int num=1;
		while(num<=max){
			for (int i = left; i <= right; i++) result[top][i]=num++;
			top++;
			for (int i = top; i <= bottom; i++) result[i][right]=num++;
			right--;
			for (int i = right; i >= left; i--) result[bottom][i]=num++;
			bottom--;
			for (int i = bottom; i >= top; i--) result[i][left]=num++;
			left++;
		}
		return result;
	
	}
```
