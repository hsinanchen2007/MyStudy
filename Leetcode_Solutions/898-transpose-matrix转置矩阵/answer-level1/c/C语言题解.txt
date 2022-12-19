采用a[i][j] = b[j][i]的解题思路，m * n 对调为 n * m。只是C语言中内存分配管理比较麻烦。

#define MAX 1000
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
	if (ASize <= 0 || ASize > MAX) {
		return NULL;
	}
	if (A == NULL || AColSize == NULL || returnSize == NULL || returnColumnSizes == NULL) {
		return NULL;
	}
	if (AColSize[0] > MAX) {
		return NULL;
	}
	if (ASize > 1 ){
		for (int i = 0; i < ASize - 1; i++) {
			if (AColSize[i] != AColSize[i + 1]) {
				return NULL;
			}
		}
	}
	*returnSize = *AColSize;
	int *tmp = (int *)calloc(*AColSize, sizeof(int));
	*returnColumnSizes = tmp;
	if (tmp == NULL) {
		return NULL;
	}
	for (int i = 0; i < *AColSize; i++) {
		tmp[i] = ASize; 
	}
	int **ret = (int **)calloc(*AColSize, sizeof(int **));
	if (ret == NULL) {
		free(*returnColumnSizes);
		return NULL;
	}
	for (int j = 0; j < AColSize[0]; j++) {
		int *content = (int *)calloc(ASize, sizeof(int));
		if (content == NULL) {
			goto Realse;
		}
		ret[j] = content;
	}
	for (int i = 0; i < ASize; i++) {
		for (int j = 0; j < AColSize[0]; j++) {
			ret[j][i] = A[i][j];
		}
	}
	//Print(ret, AColSize[0], *returnColumnSizes);
	return ret;
Realse:
	for (int j = 0; j < AColSize[0]; j++) {
		if (*ret[j] != NULL) {
			free(ret[j]);
		}
	}
	free(ret);
	free(returnColumnSizes);
	return NULL;
}