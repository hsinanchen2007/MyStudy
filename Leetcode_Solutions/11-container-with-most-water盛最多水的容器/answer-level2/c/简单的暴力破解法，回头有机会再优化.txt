### 解题思路
此处撰写解题思路

### 代码

```c
int maxArea(int* height, int heightSize){
	if(height == NULL || heightSize <= 1)
		return 0;

	int i,j,m;
	int sum = 0;
	for(i=0;i<heightSize;i++)
	{
		for(j=i+1;j<heightSize;j++)
		{
			m = (height[i]<height[j])?height[i]:height[j];
			sum = (((j-i)*m) > sum)?((j-i)*m):sum;
		}
	}
	return sum;
}
```