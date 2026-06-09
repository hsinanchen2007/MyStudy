### 解题思路
	排序后输出

### 代码

```c
#include <stdlib.h>

const void* cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
	if (arr == NULL || arrSize == 0 || k == 0) {
		*returnSize = 0;
		return arr;
	}

	qsort(arr, arrSize, sizeof(int), cmp);
	if (k > arrSize) {
		*returnSize = arrSize;
		return arr;
	}
	int *returnArray = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; ++i) {
		returnArray[i] = arr[i];
	}
	*returnSize = k;
	return returnArray;
}
```