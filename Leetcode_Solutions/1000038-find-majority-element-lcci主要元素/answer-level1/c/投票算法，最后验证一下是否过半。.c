### 解题思路
此处撰写解题思路

### 代码

```c


int majorityElement(int* nums, int numsSize)
{
	int major, count = 0, i = 0;
	while (i < numsSize)
	{
		major = count ? major : nums[i];
		count = major == nums[i] ? count + 1 : count - 1;
		i++;
	}

	const int HALF = numsSize / 2;
	count = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == major)
			count++;
	}
	return count > HALF ? major : -1;
}
```