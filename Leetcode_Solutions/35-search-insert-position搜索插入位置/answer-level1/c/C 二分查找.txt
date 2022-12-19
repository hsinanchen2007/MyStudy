### 解题思路
	二分查找入门题，注意最后处理下边界

### 代码

```c
#include <stdlib.h>

int binarySearch(int *nums, int low, int high, int target) {
	int mid = 0;
	while (low < high) {
		mid = (low + high) / 2;
		if (nums[mid] < target) low = mid + 1;
		else if (nums[mid] > target) high = mid - 1;
		else return mid;
	}
	return low;
}

int searchInsert(int* nums, int numsSize, int target) {
	if (nums == NULL || numsSize == 0) return 1;
	/* binary search */
	int low = 0;
	int high = numsSize - 1;
	int insertPos = binarySearch(nums, low, high, target);
	return nums[insertPos] >= target? insertPos : insertPos + 1;
}
```