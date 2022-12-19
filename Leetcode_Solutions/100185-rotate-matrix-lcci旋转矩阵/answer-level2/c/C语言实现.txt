两个for循环，外层for循环控制矩阵圈数，在第i圈(矩阵最外圈计第0圈)，所访问矩阵元素的行列范围均为[i,matrixSize-1-i]，内层for循环控制该圈的旋转次数，每次旋转对矩阵的四个元素进行换值操作
```
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for(int i=0; i < matrixSize / 2; i++){
		int ni = matrixSize-1-i;
        for(int j=i; j < ni; j++){
			int nj = matrixSize-1-j;
            int temp = matrix[i][j];
            matrix[i][j] = matrix[nj][i];
            matrix[nj][i] = matrix[ni][nj];
            matrix[ni][nj] = matrix[j][ni];
            matrix[j][ni] = temp;
        }
    }
}
```