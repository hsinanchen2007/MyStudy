### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
	if (r*c != numsSize*(*numsColSize)){
		*returnSize = numsSize;
		*returnColumnSizes = numsColSize;
		return nums;
	}	
	*returnColumnSizes = (int*)malloc(sizeof(int) * r);
	int **res = (int**)malloc(sizeof(int*)*r), x = 0, y = 0;
	for (int i = 0; i < r; i++){
		res[i] = (int*)malloc(sizeof(int)*c);
		(*returnColumnSizes)[i] = c;
	}

	for (int i = 0; i < numsSize; i++)
		for (int j = 0; j < *numsColSize; j++){
		if (y == c){
			y = 0; x++;
		}
		res[x][y++] = nums[i][j];
		}
    *returnSize = r;
	return res;
}
```