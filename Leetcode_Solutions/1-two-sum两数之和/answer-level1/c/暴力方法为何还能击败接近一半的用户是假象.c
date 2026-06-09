### 解题思路
暴力方法

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int *ret = (int *)malloc(sizeof(int) + sizeof(int));
	if (ret == NULL) {
		return NULL;
	}

	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				ret[0] = i;
				ret[1] = j;
				*returnSize = 2;
				return ret;
			}
		}
	}
	return NULL;
}
```