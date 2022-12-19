```

int compare(const void* p1, const void* p2)
{
	return *(int *)p1 - *(int *)p2;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

	int left = 0;
	int right = 0;
	int target = 0;
	int *pThreeNums = NULL;
	int count = 0;
	int *pColumnSizes = NULL;
	int **pRetNumsArry = NULL;

	*returnSize = 0;
	if (nums == NULL || numsSize < 3) {
		return NULL;
	}

	qsort(nums, numsSize, sizeof(int), compare);
	pRetNumsArry = (int**)malloc(numsSize * numsSize * sizeof(int*));
	for (int i = 0; i < numsSize; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		left = i + 1;
		right = numsSize - 1;
		target = 0 - nums[i];

		while (left < right) {
			if (nums[left] + nums[right] < target) {
				left++;
			}
			else if (nums[left] + nums[right] > target) {
				right--;
			} else {
				pThreeNums = (int*)malloc(3 * sizeof(int));
				pThreeNums[0] = nums[i];
				pThreeNums[1] = nums[left];
				pThreeNums[2] = nums[right];
				pRetNumsArry[count++] = pThreeNums;
				left++;
				right--;
				while (nums[left] == nums[left - 1] && (left < right)) {
					left++;
				}

				while (nums[right] == nums[right + 1] && (left < right)) {
					right--;
				}
			}
		}
	}
	*returnSize = count;
	if (count > 0) {
		pColumnSizes = (int*)malloc(count * sizeof(int));
	}
	for (int i = 0; i < count; i++) {
		pColumnSizes[i] = 3;
	}
	*returnColumnSizes = pColumnSizes;
	if (count == 0) {
		free(pRetNumsArry);
		pRetNumsArry = NULL;
	}
	return pRetNumsArry;
}

```
