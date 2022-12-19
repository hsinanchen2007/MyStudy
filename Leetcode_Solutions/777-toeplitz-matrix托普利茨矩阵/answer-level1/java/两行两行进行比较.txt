两行两行比较，每行的第i个数跟下一行的第i+1个数比较
```
public static boolean isToeplitzMatrix(int[][] matrix){
		int M = matrix.length, N = matrix[0].length;
		int[] temp1 = new int[N];
		int[] temp2 = new int[N];
		for (int i = 0; i < M-1; i++) {
			temp1 = matrix[i];
			temp2 = matrix[i+1];
			for (int j = 0; j < N-1; j++) {
				if(temp1[j]!=temp2[j+1])
					return false;
			}
		}
		return true;
	}
```
