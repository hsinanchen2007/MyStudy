### 解题思路

### 代码

```c
int cmp_int(const void* _a, const void* _b)
{
	return *(int*)_a - *(int*)_b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
    if(numsSize<3) return NULL;
	int low = 0;
	int high = 0;
	int sum = 0;
	int** ret = (int**)malloc(sizeof(int*) * (numsSize)*(numsSize) / 4);
	*returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize) / 4);
	qsort(nums, numsSize, sizeof(int), cmp_int);
	for (int i = 0; i < numsSize - 2 && nums[i] <= 0; i++) {
		low = i + 1;
		high = numsSize - 1;
		while (low < high) {
			sum = nums[low] + nums[high] + nums[i];
			if (0 == sum) {
				ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
				(*returnColumnSizes)[*returnSize] = 3;
				ret[*returnSize][0] = nums[i];
				ret[*returnSize][1] = nums[low];
				ret[*returnSize][2] = nums[high];
				(*returnSize)++;
				low++; high--;
				while ((nums[low] == nums[low - 1]) && (low < high)) low++;
				while ((nums[high] == nums[high + 1]) && (low < high)) high--;
			}
			else if (0 < sum){
				high--;
				while ((nums[high] == nums[high + 1]) && (low < high)) high--;
			}
			else{
				low++;
				while ((nums[low] == nums[low - 1]) && (low < high)) low++;
			}
		}
		while ((nums[i] == nums[i+1]) && (i < numsSize - 2)) i++;
	}
	return ret;
}
```