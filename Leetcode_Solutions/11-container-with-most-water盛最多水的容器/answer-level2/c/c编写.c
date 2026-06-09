### 解题思路
此处撰写解题思路
这题思路对了编码对了，但是在本地编译器编写测试代码的时候出现问题了，没有写出对的测试程序。
### 代码

```c
int maxArea(int* height, int heightSize){
int i = 0, j = heightSize - 1;
	int temp = 0;
	double max_area = 0;
	while (j > i)
	{
		temp = height[i] > height[j] ? height[j] : height[i];
        /*
		if (height[i] > height[j])
		{
			temp = height[j];
		}
		else
		{
			temp = height[i];
		}
        */
		if (max_area < (temp * (j - i)))
		{
			max_area = temp * (j - i);
		}
		if (height[j] > height[i])
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return max_area;
}
```