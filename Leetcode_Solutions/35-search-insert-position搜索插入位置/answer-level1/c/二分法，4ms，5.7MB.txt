### 解题思路

对于已经排序好的数组，使用二分法效率比较高。

开始二分前，先判断几种不需要二分就可以得出来的情况：

* 数组只有一个元素
* target 比首元素小
* target 比首元素大

接下来进行正常的二分法即可。

但是要注意一点，给的是有序数组，但不是等差，所以在二分判断改区间时不 +1/-1。

比如 [1 2 4 6 7] 3

左 0 (1) 右 4 (7) 中位 2 (4)

target 比 4 小，如果把中位赋值给右后还 -1，就会出现剩下的区间都比 target 小的情况。

一些见解，如有错误，轻喷。

### Code

```c
int searchInsert(int* nums, int numsSize, int target)
{
	if (numsSize == 1)
	{
		if (nums[0] >= target)
		{
			return 0;
		}
		return 1;
	}

	int left = 0;
	int right = numsSize - 1;
	if (nums[left] > target)
	{
		return 0;
	}
	if (nums[right] < target)
	{
		return numsSize;
	}

	while (right - left > 1)
	{
		if (nums[left] == target)
		{
			return left;
		}
		if (nums[right] == target)
		{
			return right;
		}
        
		int temp = (right + left + 1) / 2;
		
		if (nums[temp] == target)
		{
			return temp;
		}
		if (nums[temp] > target)
		{
			right = temp;
		}
		else
		{
			left = temp;
		}
	}

	if (right == left)
	{
		if (nums[left] >= target)
		{
			return left;
		}
		else
		{
			return right + 1;
		}
	}
	else
	{
		if (nums[left] == target)
		{
			return left;
		}
		if (nums[right] >= target)
		{
			return right;
		}
	}
	return 0;  // 不加默认出口会报错，可能是因为其他的出口都需要判断的原因
}
```