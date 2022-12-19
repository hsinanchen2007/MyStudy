```
//嵌套循环
	public static int[][] transpose(int[][] A){
		int Z = A.length;
		int H = A[0].length;
		int[][] B = new int[H][Z];
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < Z; j++) {
				B[i][j] = A[j][i];
			}
		}
		return B;
	}
```
```
//while循环
	public static int[][] transpose(int[][] A){
		int Z = A.length;
		int H = A[0].length;
		int[][] B = new int[H][Z];
		int i = 0,j = 0;
		while(i<Z||j<H-1){
			if(i==Z){
				j++;
				i = 0;
				continue;
			}
			B[j][i] = A[i][j];
			i++;
		}
		return B;
	}
```