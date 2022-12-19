### 解题思路
此处撰写解题思路

### 代码

```c


void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
	for(int i = 0; i < matrixSize; i++)
	{
		for(int j = i+1; j < *matrixColSize; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		} 
	} 
	
	int mid = matrixSize >> 1;
	for(int i = 0; i < matrixSize; i++)
	{
		for(int j = 0; j < mid; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][matrixSize-j-1];
			matrix[i][matrixSize-j-1] = temp;
		}	 
	}
}
```