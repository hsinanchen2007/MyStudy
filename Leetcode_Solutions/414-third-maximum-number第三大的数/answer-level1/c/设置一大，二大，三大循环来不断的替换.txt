### 解题思路
此处撰写解题思路

### 代码

```c
int thirdMax(int* nums, int numsSize)
{
	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
	if (numsSize == 1)
		return *nums;
	else if (numsSize == 2)
		return *nums > *(nums + 1) ? *nums : *(nums + 1);
	for (int i = 0; i < numsSize; ++i)
	{
		if (first < nums[i])
		{
			third = second;
			second = first;
			first = nums[i];
		}
		else if (first > nums[i] && second < nums[i])
		{
			third = second;
			second = nums[i];
		}
		else if (second > nums[i] && third < nums[i])
		{
			third = nums[i];
		}

	}
	if (third == LONG_MIN)
		return first;
	return third;
}
```