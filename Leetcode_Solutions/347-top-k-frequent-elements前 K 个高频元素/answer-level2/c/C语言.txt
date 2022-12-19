### 解题思路
对数组进行两次排序，就可以依次得到出现次数前K多的元素了。

### 代码

```c
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
typedef struct {
	int cnt;
	int val;
}Bucket; // 桶排序的数据类型定义

int Compare(const void *a, const void *b)
{
	return *(int*)a > *(int*)b; // 升序排列
}

int ComparePlus(const void *a, const void *b)
{
	return ((Bucket*)a)->cnt < ((Bucket*)b)->cnt;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
	*returnSize = 0;
	if (nums == NULL) {
		return NULL;
	}
	qsort(nums, numsSize, sizeof(nums[0]), Compare);
    /*
	for (int i = 0; i < numsSize; i++){
		printf("%d ", nums[i]);
	}
	printf("\n");
    */
	Bucket *bucket = (Bucket*)malloc(sizeof(Bucket) * numsSize);
	if (bucket == NULL) {
		return NULL;
	}
	memset(bucket, 0, sizeof(Bucket) * numsSize);

	// 1. 计数
	int i = 0, j = 0;
	bucket[j].cnt = 1;
	bucket[j].val = nums[0];

	for (; i < numsSize - 1; i++) {
		if (nums[i] != nums[i + 1]) {
			j++;
			bucket[j].cnt = 1;
			bucket[j].val = nums[i + 1];
		}
		else {
			bucket[j].cnt++;
		}
	}

	// 2. 排序
	qsort(bucket, j + 1, sizeof(bucket[0]), ComparePlus);
    /*
	for (int i = 0; i < numsSize; i++){
		printf("%d %d\t", bucket[i].val, bucket[i].cnt);
	}
	printf("\n");
    */
	for (i = 0; i < k; i++) {
		nums[(*returnSize)++] = bucket[i].val;
	}
    free(bucket);
	return nums;
}

```