### 解题思路

![image.png](https://pic.leetcode-cn.com/601be8df60364d48e9c0741bd8a1f75f01dfff2bc288c2de60582d4e94efa694-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rltAlloc(int row, int col)
{
	int i, j;
	int** rlt = NULL;
	rlt = (int**)calloc(row, sizeof(int*));
	if (rlt == NULL) {
		return NULL;
	}
	for (i = 0; i < row; i++) {
		rlt[i] = (int*)calloc(col, sizeof(int));
		if (rlt[i] == NULL) {
			break;
		}
	}
	if (i == row) {
		return rlt;
	}
	for (j = 0; j < i; j++) {
		free(rlt[j]);
	} 
	free(rlt);
	return NULL;
}
inline int cal(int **M, int row, int col, int ci, int cj)
{
	int i, j;
	int sum = 0, cnt = 0;
	int srow, erow, scol, ecol;
	srow = (ci - 1) >= 0 ? (ci - 1) : 0;
	erow = (ci + 1) <= row ? (ci + 1) : row;
	scol = (cj - 1) >= 0 ? (cj - 1) : 0;
	ecol = (cj + 1) <= col ? (cj + 1) : col;
	for (i = srow; i <= erow; i++) {
		for (j = scol; j <= ecol; j++) {
			sum += M[i][j];
			cnt++;
		}
	}
	return sum / cnt;
}
int** imageSmoother(int** M, int MSize, int* MColSize, int* returnSize, int** returnColumnSizes){
	int i, j;
	int **rlt = NULL;
	rlt = rltAlloc(MSize, MColSize[0]);
	if (rlt == NULL) {
		return NULL;
	}
	for (i = 0; i < MSize; i++) {
		for (j = 0; j < MColSize[i]; j++) {
			rlt[i][j] = cal(M, MSize - 1, MColSize[i] - 1, i, j);
		}
	}
	*returnSize = MSize;
	*returnColumnSizes = MColSize;
	return rlt;
}
```