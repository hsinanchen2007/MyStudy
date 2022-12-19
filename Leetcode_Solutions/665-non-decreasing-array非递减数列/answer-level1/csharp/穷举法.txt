```
	public bool CheckPossibility(int[] nums)
	{
		var numsTemp = nums.ToArray();
		for (int i = 0; i < nums.Length - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				nums[i] = nums[i + 1];
				numsTemp[i + 1] = numsTemp[i];
				break;
			}
		}
		var isOK = true;
		var isOKTemp = true;
		for (int i = 0; i < nums.Length - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				isOK = false;
			}
		}
		for (int i = 0; i < numsTemp.Length - 1; i++)
		{
			if (numsTemp[i] > numsTemp[i + 1])
			{
				isOKTemp = false;
			}
		}
		return isOK || isOKTemp;
	}
```
在i和i + 1出现递减的时候, 尝试让nums[i] = nums[i + 1], 重新开始判断, 如果是非递减, 返回true, 否则, 让nums[i + 1] = nums[i], 再次重新判断, 如果是非递减, 返回true, 否则, 返回false
