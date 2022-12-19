### 解题思路
偷懒 直接排序

### 代码

```c
#include <stdlib.h>

int cmp(const void *a, const void *b) 
{
	return *(int*)a - *(int*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
	if (nums == NULL || numsSize == 0)
	{
		*returnSize = 0;
		return nums;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = numsSize;
	return nums;
}
```