### 解题思路
就是一圈一圈的转换，搞明白下标什么都好说。

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
	int d = matrixSize - 1 ;
	for (int i = 0; i <matrixSize/2; ++i)
	{
		for (int j = i; j < i + d; ++j)
		{
			int t1 = matrix[i][j], t2 = matrix[j][matrixSize - 1 - i], t3 = matrix[matrixSize - 1 - i][matrixSize - 1 - j], t4 = matrix[matrixSize - 1 - j][i];
			matrix[j][matrixSize - 1 - i] = t1;
			matrix[matrixSize - 1 - i][matrixSize - 1 - j] = t2;
			matrix[matrixSize - 1 - j][i] = t3;
			matrix[i][j] = t4;
		}
		d -= 2;
	}
}
```