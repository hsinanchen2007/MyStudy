int findUnsortedSubarray(int* nums, int numsSize) {
	int i = 0;
	int j = numsSize - 1;
	if (numsSize == 1)
	{
		return 0;
	}
	if (nums[j] < nums[i])
	{
		return numsSize;
	}
	i++;
	while (nums[i - 1] <= nums[i] && i < numsSize - 1)
	{
		i++;
	}
	j--;
	while (nums[j + 1] >= nums[j] && j > 0)
	{
		j--;
	}
	if (j == 0 && i == numsSize-1)
	{
		return 0;
	}
	j++;
	i--;
	int a = i;
	int b = j;
	int min = nums[i];
	int max = nums[i];
	while (i <= j)
	{
		if (nums[i] < min)
		{
			min = nums[i];
		}
		if (nums[i] > max)
		{
			max = nums[i];
		}
		i++;
	}
	while (a > 0)
	{
		if (nums[a - 1] <= min)
		{
			break;
		}
		a--;
	}
	while (b < numsSize - 1)
	{
		if (nums[b + 1] >= max)
		{
			break;
		}
		b++;
	}
	return b - a + 1;
}
