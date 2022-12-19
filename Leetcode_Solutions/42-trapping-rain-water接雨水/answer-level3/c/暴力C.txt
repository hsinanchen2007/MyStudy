### 解题思路
小白暴力解法
![image.png](https://pic.leetcode-cn.com/8226c63aeb5b8a7103c378500c55125a894c9871df58ae6ba04cbb34db96bf94-image.png)

![1.jpg](https://pic.leetcode-cn.com/d9d1db8bcebed4982b1e95e6d6ea7af22d850a65b19897941a0c4fbed29c0d56-1.jpg)



### 代码

```c
int trap(int* height, int heightSize)
{
    if(heightSize == 0 || heightSize == 1)
		//如果数组长度为0或者是1的话，是接不到雨水滴
        return 0;
    int max = 0;
    int maxIndex = 0;
	//找出数组中最大的数，并记录这个数和下标
	//如果有多个最大的数，记录遇到的第一个数的下标
    for(int i = 0; i < heightSize; i++)
    {
        if(height[i] > max)
        {
            max = height[i];
            maxIndex = i;
        }
    }
    int volume = heightSize * max;
	//算出整个大矩形的面积
    int maxIndexLeftOld = maxIndex, maxLeft, maxIndexLeftNew = maxIndex - 1;
	//从最大的开始往前面把多加的雨水减掉
    while(maxIndexLeftNew != -1)
    {
        maxLeft = 0;
        for(int i = maxIndexLeftNew; i >= 0; i--)
        {
            if(height[i] >= height[maxIndexLeftNew])
            {
                maxLeft = height[i];
                maxIndexLeftNew = i;
            }
        }
        volume -= (max - height[maxIndexLeftNew]) * (maxIndexLeftOld - maxIndexLeftNew);
        maxIndexLeftOld = maxIndexLeftNew;
        maxIndexLeftNew -= 1;
    }
    int maxIndexRightOld = maxIndex, maxRight, maxIndexRightNew = maxIndex + 1;
	//从最大的开始往后面把多加的雨水减掉
    while(maxIndexRightNew != heightSize)
    {
        maxRight = 0;
        for(int i = maxIndexRightNew; i < heightSize; i++)
        {
            if(height[i] >= height[maxIndexRightNew])
            {
                maxRight = height[i];
                maxIndexRightNew = i;
            }
        }
        volume -= (max - height[maxIndexRightNew]) * (maxIndexRightNew - maxIndexRightOld);
        maxIndexRightOld = maxIndexRightNew;
        maxIndexRightNew += 1;
    }
	//减掉容器的体积
    for(int i = 0; i < heightSize; i++)
    volume -= height[i];
    return volume;
}
```