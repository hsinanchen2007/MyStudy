### 解题思路
从第一项开始正向寻找比它大的数，计算中间的积水并累加，反复至后方无更大数，之后反方向再进行一次。
### 代码

```c
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)


int trap(int* height, int heightSize)
{
	if (heightSize == 0)return 0;
	int sumtrap = 0,sumrock,highest = heightSize - 1;
	int i = 0, j = 0;
	while (i < highest)
	{
		j = i + 1;
		sumrock = 0;
		while (height[j] < height[i])
		{
			sumrock += height[j];
			if (j == heightSize - 1)
			{
				highest = i;
				goto next;//如果第i项以后没有再比他大的
			}
			j++;
		}
		sumtrap += height[i] * (j - i - 1) - sumrock;
		i = j;
	}
next:
	i = heightSize - 1;
	while (i > highest)
	{
		j = i - 1;
		sumrock = 0;
		while (height[j] < height[i])
		{
			sumrock += height[j];
			j--;
		}
		sumtrap += height[i] * (i - j - 1) - sumrock;
		i = j;
	}
	return sumtrap;
}
```