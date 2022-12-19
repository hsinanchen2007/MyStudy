### 解题思路
此处撰写解题思路
先排序再找序列
![image.png](https://pic.leetcode-cn.com/b4e4e38c428fc7e8ea02e76524df9cc99e0ad9967f15e34bfe34491af89c75c8-image.png)

### 代码

```c
int findUnsortedSubarray(int* nums, int numsSize)
{
	void QuickSort(int a[],int left,int right);
	int tmp[numsSize];
	int i,start = numsSize-1,end = 0;
	for(i = 0;i < numsSize;i++)
	{
		tmp[i] = nums[i];
	}
	QuickSort(tmp,0,numsSize-1);
	for(i = 0;i < numsSize;i++)
	{
		if(nums[i] != tmp[i])
		{
			start = start<i?start:i;	
			end = end>i?end:i;
		}
	}
	return (end-start)>0?end-start+1:0;
}
void QuickSort(int a[],int left,int right)
{
	if(left < right)
	{
		int pivotor = Partition(a,left,right);
		QuickSort(a,left,pivotor-1);
		QuickSort(a,pivotor+1,right);
	}
}
int Partition(int a[],int left,int right)
{
	int key = a[left];
	while(left < right)
	{
		while(a[right] >= key && left < right)
			right--;
		a[left] = a[right];
		while(a[left] <= key && left < right)
			left++;
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}
```