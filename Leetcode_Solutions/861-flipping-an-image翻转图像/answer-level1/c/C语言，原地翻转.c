```
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
	int row;
	int left, right;
	int tmp;
	int i;
	for (row = 0; row < ASize; row++) {
		left = 0;
		right = AColSize[row] - 1;
		while(left < right) {
			tmp = A[row][left];
			A[row][left] = A[row][right];
			A[row][right] = tmp;
			left++;
			right--;
		}
		for (i = 0; i < AColSize[row]; i++) {
			A[row][i] = A[row][i] == 0 ? 1 : 0;
		}
	}
	*returnSize = ASize;
	*returnColumnSizes = AColSize;
	return A;
}
```
