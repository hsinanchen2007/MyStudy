### 解题思路
排序以后，从后边往前边取，这个是关键

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p1, const void *p2)
{
	return *(const int *)p1 - *(const int *)p2;
}

void wiggleSort(int *nums, int numsSize)
{
	int *ans;
	int loop;
	int mid;
	int left;
	int right;
	int index;
	if (!nums || numsSize == 0 || numsSize == 1)
		return;
	ans = (int *)malloc(sizeof(int) * numsSize);
	qsort(nums, numsSize, sizeof(int), compare);
	mid = (numsSize - 1) / 2;
	left = mid;
	right = numsSize - 1;
	index = 0;
	//printf("%d %d\n", left, right);
	for (loop = 0; loop < numsSize; loop++) {
		if (!(loop % 2)) {
			ans[loop] = nums[left--];
		} else {
			ans[loop] = nums[right--];
		}
	}
	memcpy(nums, ans, sizeof(int) * numsSize);	
}
```