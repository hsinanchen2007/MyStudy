### 解题思路
将原数组与排序后的数组进行比较，找到左右边界即可
![image.png](https://pic.leetcode-cn.com/0cbb50011aab182c462fb126f79a35737d4b93af12f75b5f778469ab1f8682c5-image.png)

### 代码

```c
int cmp(const void *a, const void *b)
{
	return *(int*)a > *(int*)b;
}
int findUnsortedSubarray(int* nums, int numsSize){
	int *buf = NULL;
	int l = 0, r = numsSize - 1;
	buf = (int*)calloc(numsSize, sizeof(int));
	if (buf == NULL) {
		return -1;
	}
	memcpy(buf, nums, numsSize * sizeof(int));
	qsort(buf, numsSize, sizeof(int), cmp);
	for (l = 0; l < numsSize; l++) {
		if (buf[l] != nums[l]) {
			break;
		}
	}
	for (r = numsSize - 1; r >= 0; r--) {
		if (buf[r] > nums[r]) {
			break;
		}
	}
	free(buf);
	return r > l ? r - l + 1 : 0;
}
```