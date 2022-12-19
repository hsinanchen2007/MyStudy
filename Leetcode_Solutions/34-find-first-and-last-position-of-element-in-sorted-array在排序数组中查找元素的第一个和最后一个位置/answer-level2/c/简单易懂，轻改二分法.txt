### 解题思路
以往二分法是查找某一个元素，这次二分法是查找两个元素，所以把二分法的查找过程写两次，修改一下找到的条件就行了。

### 代码

```c
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int *ret = (int*)malloc(2 * sizeof(int));
	*returnSize = 2;
	ret[0] = ret[1] = -1;
	int low = 0, hi = numsSize - 1, mid;
	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (nums[mid] == target && (mid == 0 ||nums[mid - 1] < target ))
		{
			ret[0] = mid;
			break;
		}
		else if (nums[mid] >= target)
			hi = mid - 1;
		else
			low = mid + 1;
	}
	if (ret[0] == -1)
		return ret;
	low = 0, hi = numsSize - 1;
	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if (nums[mid] == target && (mid == numsSize - 1||nums[mid + 1] > target))
		{
			ret[1] = mid;
			break;
		}
		else if (nums[mid] <= target)
			low = mid + 1;
		else
			hi = mid - 1;
	}
	return ret;
}
```