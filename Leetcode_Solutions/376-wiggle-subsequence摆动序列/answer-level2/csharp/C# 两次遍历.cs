其实不管怎么移除元素, 最终的结果只有两种情况.
1. 第一个摆动为正
2. 第一个摆动为负
所以我们只要把两种情况都过一遍, 看哪种序列长就可以了.

```csharp
	public int WiggleMaxLength(int[] nums)
	{
		var res = 1;
		for (int j = 0; j < 2; j++)
		{
			var isPositive = j % 2 == 0;
			var count = 1;
			for (int i = 1; i < nums.Length; i++)
			{
				if (isPositive && nums[i] - nums[i - 1] > 0)
				{
					isPositive = !isPositive;
					count++;
				}
				if (!isPositive && nums[i] - nums[i - 1] < 0)
				{
					isPositive = !isPositive;
					count++;
				}
			}
			res = Math.Max(res, count);
		}
		return Math.Min(res, nums.Length);
	}
```
