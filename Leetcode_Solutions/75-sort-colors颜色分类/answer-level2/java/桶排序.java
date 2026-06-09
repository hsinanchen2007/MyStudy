感觉没有比桶排序更简单的了，按照题意，总共就三种颜色，所以可以设置数组长度为3的“桶”，计算出每个不同颜色的桶中的数量，然后重构nums数组即可，消耗的也是常数级的空间，算法复杂度O(n)。代码如下：
```
public void sortColors(int[] nums) {
		int[] result = new int[3];
		for(int i = 0 ;i<nums.length;i++)
		{
			int index = nums[i] % 3;
			result[index] = result[index] +1;
		}
		int i = 0;
		int j = 0;
		while(i<3)
		{
			int count = result[i];

			while(count > 0)
			{
				nums[j++] = i;
				count--;
			}
			i++;
		}
	}
```