### 解题思路
以后再用C++map重写一遍，暴力法时间复杂度太高了，C手撸hash表太麻烦
### 代码

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int *ret = (int*)malloc(2 * sizeof(int));
	
	for (int i = 0; i < numsSize; ++i)
	{
		for (int j = 0; j < numsSize; ++j)
		{
			if (i == j)
				continue;
			if (nums[i] + nums[j] == target)
			{
				*returnSize = 2;
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	return ret;
}
```