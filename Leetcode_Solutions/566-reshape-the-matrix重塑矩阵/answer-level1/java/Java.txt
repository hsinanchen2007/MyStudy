先判断重塑的矩阵是否合理，如果合理则读取nums矩阵的每一个数赋值给res，使用row和col来控制res的行和列。
也可以先用一个一维数组读取nums的所有值，再赋值给res。
```
public static int[][] matrixReshape(int[][] nums,int r,int c){
		int[][] res = new int[r][c];
		int row = 0,col = 0;
		//如果r*c不等于矩阵的行*列,则不合理，返回原数组
		if(r*c!=nums.length*nums[0].length)
			return nums;
		for (int i = 0; i < nums.length; i++) {
			for (int j = 0; j < nums[0].length; j++) {
				if(col==c){
					row++;
					col = 0;
				}
				res[row][col++] = nums[i][j];
			}
		}
		return res;
	}
```
