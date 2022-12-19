### 解题思路
此处撰写解题思路

### 代码

```c
int maxArea(int* height, int heightSize)
{
	int start = 0,end = heightSize-1,maxarea=0,tmp,gap;
	while(start != end)
	{
		tmp = *(height+start) > *(height + end)?*(height+end):*(height+start);
		gap = end-start;
		maxarea = (gap*tmp)>maxarea?gap*tmp:maxarea;
		*(height+start) > *(height + end)?end--:start++;
	}
	return maxarea;
}
```