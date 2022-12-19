
```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
	int temp;
	int i,j;
	for(i=0;i<matrixSize;i++){
		for(j=i-1;j>=0;j--){
			temp=matrix[i][j];
			matrix[i][j]=matrix[j][i];
			matrix[j][i]=temp;
		}
	}

	for(i=0;i<matrixSize;i++){
		int start=0;
		int end= *matrixColSize-1;
		while(start<end){
			temp=matrix[i][start];
			matrix[i][start++]=matrix[i][end];
			matrix[i][end--]=temp;		
		}
	}
}
```