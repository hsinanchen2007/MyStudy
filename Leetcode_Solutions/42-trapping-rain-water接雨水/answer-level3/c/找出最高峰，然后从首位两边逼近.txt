## 解题思路
利用木桶效应的思想，如果想盛住水滴，需要两边至少一样高，或者一边高，一边矮。因此，在遍历数组每个元素的时候，先找出两个木桶的边界，然后算出两个边界之间的空空，然后在空空区间遍历，减去实际不为零的数目，就得到最后水滴的数目。

### 代码

```c


int trap(int* height, int heightSize){
int min(int a, int b);
	int max(int a, int b);
	int i, j, k, min_value, drop, max_pos, max_value;;
	min_value = 0; drop = 0;//雨滴数
	max_pos = 0;//初始化
	max_value = 0;
	for (i = 0; i < heightSize; i++)
	{
		if(height[i] > max_value) 
         {
             max_value = height[i]; 
         max_pos = i;
         }
		
	}
	if (max_pos != 0)
	{
		for (i = 0; i <= max_pos - 1; i++)
		{
			if (!height[i]) { continue; }
			for (j = i + 1; j <= max_pos; j++)
			{
				if (height[i] <= height[j])

				{
					min_value = min(height[i], height[j]);
					drop = drop + min_value * abs(j - i - 1);
					printf("I:%d, j:%d, drop:%d\n", i, j, drop);
					for (k = i + 1; k < j; k++)
					{
						drop = drop - height[k];
						printf("drop: %d,height[%d]:%d\n", drop, k, height[k]);
					}
					i = j - 1;
					break;
				}
			}
		}
	}
	for (i =heightSize-1; i >= max_pos+1; i--)
	{
		if (!height[i]) { continue; }
		for (j = i-1; j >= max_pos; j--)
		{
			if (height[i] <= height[j])

			{
				min_value = min(height[i], height[j]);
				drop = drop + min_value * abs(i-j - 1);
				printf("i:%d, j:%d, drop:%d\n", i, j, drop);
				for (k = i - 1; k > j; k--)
				{
					drop = drop - height[k];
					printf("drop: %d,height[%d]:%d\n", drop, k, height[k]);
				}
				i = j + 1;
				break;
			}
		}
	}
	printf("drop: %d\n", drop);
    return drop;
}
int min(int a, int b)
{
	return a <= b ? a : b;
}

```