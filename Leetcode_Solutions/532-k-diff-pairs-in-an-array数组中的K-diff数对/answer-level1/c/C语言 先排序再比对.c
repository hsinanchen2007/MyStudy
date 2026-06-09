### 解题思路
先排序，然后逐个比对
![image.png](https://pic.leetcode-cn.com/f604f3c1e196c6a0f75d49c24c0e0489df95b866d849516de50cfdf1b6d2cb87-image.png)

### 代码

```c
int cmp(const void *a, const void *b)
{
	return *(int*)a > *(int*)b;
}
int findPairs(int* nums, int numsSize, int k){
	int i, j;
	int cnt = 0;
	int lastpair[2], pair[2];
	if (numsSize < 2 || k < 0) {
		return 0;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	for (i = 0; i < numsSize - 1; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (k != (nums[j] - nums[i])) {
				continue;
			}
			if ((cnt == 0) || (lastpair[0] != nums[i] && lastpair[1] != nums[j])) {
				lastpair[0] = nums[i];
				lastpair[1] = nums[j];
				cnt++;
			}
		}
	}
	return cnt;
}
```