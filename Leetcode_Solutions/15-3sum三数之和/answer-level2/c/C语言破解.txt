对于该题目有个疑问，6 * (numsSize + 1)空间大小是如何确定的？如果采用了分配空间满时，则翻倍的做法（如注释掉的部分），本地执行不报错，而力扣报内存越界。比较怪异。
#define MAX 3
int Cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int **Resize(int **ret, int space)
{
	int **reSpace = (int **)calloc(2 * space, sizeof(int *));
	if (reSpace == NULL) {
		exit(-1);
	}
	for (int i = 0; i < space; i++) {
		reSpace[i] = ret[i];
	}
	free(ret);
	return reSpace;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	if (numsSize < MAX) {
		*returnSize = 0;
		return NULL;
	}
	qsort(nums, numsSize, sizeof(int), Cmp);
	//if ((long long int)nums[0] * nums[numsSize - 1] > 0) {
    if(nums[0] > 0 || nums[numsSize - 1] < 0) {
		*returnSize = 0;
		return NULL;
	}
	int space = 6 * (numsSize + 1);
    //int space = numsSize;
	int **ret = (int **)calloc(space, sizeof(int *));
	if (ret == NULL) {
		exit(-1);
	}
	*returnSize = 0;
	for (int i = 0; i < numsSize - 2; i++) {
		if (nums[i] > 0) {
			break;
		}
		int j = i + 1;
		if (i > 0 && nums[i - 1] == nums[i]) {
			continue;
		}
		int k = numsSize - 1;
		while (j < k) {
			if (nums[i] + nums[j] + nums[k] == 0) {
				int *re = (int *)calloc(MAX, sizeof(int));
				if (re == NULL) {
					exit(-1);
				}
				re[0] = nums[i];
				re[1] = nums[j];
				re[2] = nums[k];
				//if (*returnSize > space - 1) {
					//space *= 2;
					//ret = Resize(ret, space);
				//}
				ret[*returnSize] = re;
				*returnSize += 1;
				j++;
				k--;
				while (j < k && nums[j] == nums[j - 1]) {
					j++;
				}
				while (j < k && nums[k] == nums[k + 1]) {
					k--;
				}
			}
			if (nums[i] + nums[j] + nums[k] > 0) {
				k--;
				while (k > j && nums[k] == nums[k + 1]) {
					k--;
				}
			}
			if (nums[i] + nums[j] + nums[k] < 0) {
				j++;
				while (j < k && nums[j] == nums[j - 1]) {
					j++;
				}
			}
		}
	}
    if (*returnSize == 0) {
        free(ret);
        return NULL;
    }
	*returnColumnSizes = (int *)calloc(*returnSize, sizeof(int));
	if (*returnColumnSizes == NULL) {
		exit(-1);
	}
	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = MAX;
	}
	return	ret;
}
