### 解题思路
摩尔投票的核心就是不同的同归于尽，同类不自残，剩下的一定是大多数
```
int* majorityElement(int* nums, int numsSize, int* returnSize) {
	int *res = (int*)malloc(sizeof(int) * 2);
	*returnSize = 0;
	int count1 = 0;
	int count2 = 0;
	int current1 = 0;
	int current2 = 0;
	for (int i = 0; i < numsSize; i++) {
		
		if (nums[i] == current1) {
			count1++;
		}
		else if (nums[i] == current2) {
			count2++;
		}
		else if (count1 == 0) {
			count1 = 1;
			current1 = nums[i];
		}
		else if (count2 == 0) {
			count2 = 1;
			current2 = nums[i];
		}
		else {
			count1--;
			count2--;
		}
	}
	count1 = count2 = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == current1) count1++;
		else if (nums[i] == current2) count2++;
	}
	if (count1 > numsSize / 3) res[(*returnSize)++] = current1;
	if (count2 > numsSize / 3) res[(*returnSize)++] = current2;
	return res;
}
```


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
	int *res = (int*)malloc(sizeof(int) * 2);
	*returnSize = 0;
	int count1 = 0;
	int count2 = 0;
	int current1 = 0;
	int current2 = 0;
	for (int i = 0; i < numsSize; i++) {
		
		if (nums[i] == current1) {
			count1++;
		}
		else if (nums[i] == current2) {
			count2++;
		}
		else if (count1 == 0) {
			count1 = 1;
			current1 = nums[i];
		}
		else if (count2 == 0) {
			count2 = 1;
			current2 = nums[i];
		}
		else {
			count1--;
			count2--;
		}
	}
	count1 = count2 = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == current1) count1++;
		else if (nums[i] == current2) count2++;
	}
	if (count1 > numsSize / 3) res[(*returnSize)++] = current1;
	if (count2 > numsSize / 3) res[(*returnSize)++] = current2;
	return res;
}
```