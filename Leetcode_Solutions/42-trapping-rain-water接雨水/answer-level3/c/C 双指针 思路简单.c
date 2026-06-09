对于i， 要求它能接的水 w[i]，需要知道它左边的最大值，右边的最大值，然后再求两个最大值的最小值。
需要同时知道 i 左右两个的最大值，那么整个算法的复杂度是N2。
但其实并不用同时知道这两个最大值。

对于i来说，假设知道它左边的最大值left，以及右边的一个值（并不是最大）right
若left < right ，那么 w[i] = left - height[i];
  left > right 那么此时 w[i] 是求不出来的。
虽然算不出来w[i]，但是也可以把问题向前推进。
取 j > i, 将right进一步明确为j右边的最大值（此时right显然仍是i右边的一个值），left即为j左边的一个值
  left > right 那么此时 w[j] = right - height[j];
 left = right 时，可划分到两种情况中去

这样无论left，right大小如何，都能计算出一个w

计算一次后，移动计算完成的i/j，并且更新对应的left/right。
最后确定循环的条件，循环体开始时，w[i]、w[j] 都是没有被计算的，所以循环条件应该是i <= j。
这样 i = j 时也能被计算。

边界条件，i、j都不能位于数组边界（此时left、right不存在），所以有heightSize >=3；
因此需要加一个判断。

```
int trap(int* height, int heightSize){
	
	if(heightSize < 3)
	{
		return 0;
	}
	
	int left = height[0], right = height[heightSize - 1];
	int i = 1, j = heightSize - 2;
	int ret = 0;
	
	while(i <= j)
	{
		if(left < right)
		{
			if(height[i] < left)
			{
				ret += left - height[i];
			}
			else
			{
				left = height[i];
			}
			i++;	
		}
		else
		{
			if(height[j] < right)
			{
				ret += right - height[j];
			}
			else
			{
				right = height[j];
			}
			j--;
		}
	}
	return ret;
}
```
