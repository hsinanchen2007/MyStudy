```
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int arr[100][100];
    int **res = (int **)malloc(sizeof(int *) * 100);
	// 初始化
	int i, j;
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			arr[i][j] = 0;
		}
	}
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;
	// 计算每行元素
	for (i = 2; i < numRows; i++) {
		arr[i][0] = 1;
		j = 0;
		while (arr[i - 1][j] != 0 && arr[i - 1][j + 1] != 0) {
			arr[i][j + 1] = arr[i - 1][j] + arr[i - 1][j + 1];
			j++;
		}
		arr[i][j + 1] = 1;
	}
    // 输出
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * numRows);
	for (i = 0; i < numRows; i++) {
        res[i] = (int *)malloc(sizeof(int) * 100);
        returnColumnSizes[0][i] = 0;
        j = 0;
		while (arr[i][j] != 0) {
            res[i][j] = arr[i][j];
            returnColumnSizes[0][i]++;
            j++;
        }
	}
    * returnSize = numRows;    
    return res;
}
```
