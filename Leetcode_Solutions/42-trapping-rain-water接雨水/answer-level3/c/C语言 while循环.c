### 解题思路
1.先找到一个最大值，从而将整个数组分成两半，最开始maxl=maxr，maxl和maxr都是下标；
2.[0,maxl)中找到一个最靠近maxl的最大值下标max_left;
(maxr,heightSzie-1]中找到一个最靠近maxr的最大值下标max_right;
3.然后将区间[max_left+1,maxl-1]中每一个下标对应的值与height[max_left]做差，累计相加；
将区间[maxr+1,max_rigth-1]中每一个下标对应的值与height[max_right]做差，累计相加；
很明显，height[max_left]是大于区间内每一个下标对应的值的，height[max_rigth]也是一样的。
4.令maxl=max_left,maxr=max_rigth;
5.直到maxl=0左边循环结束，直到maxr=heightSize-1右边循环结束。

### 代码

```c
int trap(int* height, int heightSize){
    if(heightSize==0 || heightSize==1 || heightSize==2)
        return 0;
    int maxl=0, maxr = 0;
	int i;
	int count = 0;
	//找到最大值的下标
	for (i = 1; i<heightSize; i++)
	{
		if (height[i]>height[maxl])
			maxl = i;
	}
	maxr = maxl;
	//0-max
	while (maxl != 0)
	{
		int max_left = maxl - 1;
		//找到最大值左边的靠近最大值的第二大的值
		for (i = maxl - 1; i >= 0; i--)
		{
			if (height[i]>height[max_left])
				max_left = i;
		}
		//计算两个最大值间雨水的体积
		for (i = max_left + 1; i<maxl; i++)
		{
			count += height[max_left] - height[i];
		}
		maxl = max_left;
	}
	//max-heightSize
	while (maxr != heightSize - 1)
	{
		int max_right = maxr + 1;
		for (i = max_right+1; i < heightSize; i++)
		{
			if (height[i]>height[max_right])
				max_right = i;
		}
		for (i = maxr+1; i<max_right; i++)
		{
			count += height[max_right] - height[i];
		}
		maxr = max_right;
	}
    return count;
}
```

