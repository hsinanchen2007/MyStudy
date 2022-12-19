```
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i, j;
	int *ret = NULL_PTR;
	*returnSize = 2;
	ret = (int*)malloc(sizeof(int) * 2);
	ret[0] = ret[1] = 0;
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	return ret;
}
```
