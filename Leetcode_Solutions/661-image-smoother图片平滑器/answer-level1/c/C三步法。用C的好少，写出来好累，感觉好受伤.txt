![1.png](https://pic.leetcode-cn.com/3733de250e8c2cd16161edfaa09f4fda10ace7d43b89ccd2e69b64b734a6b32a-1.png)

### 解题思路
方法比较笨：
首先以列为单位，将每个元素的上、中、下，写入res；
其次以排为单位，将每个元素和的左、中、右，写入M；
最后判断要除以2、3、4、6、9的几种情况，再次写入res。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** M, int MSize, int* MColSize, int* returnSize, int** returnColumnSizes){
	if (MSize == 1 && *MColSize == 1){
		*returnSize = 1;
		** returnColumnSizes = 1;
		return M;
	}
	int **res = (int**)malloc(sizeof(int*)*MSize);
	*returnSize = MSize;
	for (int i = 0; i < MSize; i++){
		res[i] = (int*)malloc(sizeof(int)*(*MColSize));
		(*returnColumnSizes)[i] = *MColSize;
	}
	for (int i = 0; i < MSize; i++)
		for (int j = 0; j < *MColSize; j++)
			if (MSize == 1)
				res[i][j] = M[i][j];
			else if (i == 0 && MSize>1)
				res[i][j] = M[i][j] + M[i + 1][j];
			else if (i != 0 && i + 1 < MSize)
				res[i][j] = M[i][j] + M[i - 1][j] + M[i + 1][j];
			else if (i != 0 && i + 1 == MSize)
				res[i][j] = M[i][j] + M[i - 1][j];	
	for (int i = 0; i < MSize; i++)
		for (int j = 0; j < *MColSize; j++)
			if (*MColSize == 1)
				M[i][j] = res[i][j];
			else if (j == 0 && *MColSize>1)
				M[i][j] = res[i][j] + res[i][j + 1];
			else if (j != 0 && j + 1 < *MColSize)
				M[i][j] = res[i][j] + res[i][j - 1] + res[i][j + 1];
			else if (j != 0 && j + 1 == *MColSize)
				M[i][j] = res[i][j] + res[i][j - 1];		
	for (int i = 0; i < MSize; i++)
		for (int j = 0; j < *MColSize; j++)
			if ((MSize == 1 || *MColSize == 1) && (i + j == 0 || i + j + 2 == MSize + *MColSize))
				res[i][j] = M[i][j] / 2;
			else if ((MSize == 1 || *MColSize == 1) && (i + j > 0 && i + j + 2 < MSize + *MColSize))
				res[i][j] = M[i][j] / 3;
			else if ((MSize > 1 && *MColSize > 1) && ((i + j == 0) || (i + j + 2 == MSize + *MColSize) || (i == 0 && j == *MColSize - 1) || (i == MSize - 1 && j == 0)))
				res[i][j] = M[i][j] / 4;
			else if ((MSize > 2 && *MColSize > 2) && (i > 0 && i < MSize - 1 && j>0 && j < *MColSize - 1))
				res[i][j] = M[i][j] / 9;
			else
				res[i][j] = M[i][j] / 6;	
	return res;
}
```