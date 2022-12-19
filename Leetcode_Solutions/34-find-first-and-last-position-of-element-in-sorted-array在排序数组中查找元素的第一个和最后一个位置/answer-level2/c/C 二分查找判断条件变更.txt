### 解题思路
	用二分查找写了半天总是有些条件不满足，没想到是要用两次二分查找，分别查找左边界和右边界。
	两个地方要注意下：
	1）while判断low要小于等于high，因为如果没有等于，两个相同元素的数组情况就会出错
	2）nums[mid]==target条件出现时根据方法传进来的标志位来判断是要找左边界还是右边界，进而调整low和high的值

### 代码

```c
#include <stdlib.h>

int binarySearch(int *nums, int *returnArray, int low, int high, int target, int searchFlag) {
	int mid = 0;
	int firstFlag = 0;
	int retVal = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (nums[mid] < target) {
			low = mid + 1;
		}
		else if (nums[mid] > target) {
			high = mid - 1;
		}
		else {
			firstFlag = 1;
			if (searchFlag == 0) {
				// left
				retVal = mid;
				high = mid - 1;
			}
			else {
				// right
				retVal = mid;
				low = mid + 1;
			}
		}
	}
	if (firstFlag == 1) {
		return retVal;
	}
	return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int *returnArray = (int*)malloc(sizeof(int) * 2);
	if (nums == NULL || numsSize == 0) {
		returnArray[0] = -1;
		returnArray[1] = -1;
		*returnSize = 2;
	}
	int low = 0;
	int high = numsSize - 1;
	int searchFlag = 0;
	int leftPos = binarySearch(nums, returnArray, low, high, target, searchFlag);
	searchFlag = 1;
	int rightPos = binarySearch(nums, returnArray, low, high, target, searchFlag);
	returnArray[0] = leftPos;
	returnArray[1] = rightPos;
	*returnSize = 2;
	return returnArray;
}
```