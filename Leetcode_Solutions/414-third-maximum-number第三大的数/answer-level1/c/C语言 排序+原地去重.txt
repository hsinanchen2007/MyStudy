### 解题思路
先从大到小排序
然后原地去除重复的数字
如果剩余大于等于3，那么返回第3个，否则返回第1个（也就最大的）
![image.png](https://pic.leetcode-cn.com/46af9befbcde2198f6641b54569759f4b5bb98a4663eede1da09bc2d87e1c450-image.png)


### 代码

```c
int cmp(const void *a, const void *b)
{
	return *(int*)a < *(int*)b; 
}
int thirdMax(int* nums, int numsSize){
	int i, j;
	int last;
	qsort(nums, numsSize, sizeof(int), cmp);
	last = nums[0];
	for (i = 1, j = 1; i < numsSize; i++) {
		if (last == nums[i]) {
			continue;
		}
		last = nums[i];
		nums[j++] = last;
	}
	return j < 3 ? nums[0] : nums[2];
}
```