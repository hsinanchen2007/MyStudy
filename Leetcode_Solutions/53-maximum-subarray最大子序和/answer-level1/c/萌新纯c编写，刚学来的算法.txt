### 解题思路
用的是刚学来的动态数据分析里面的状态转移算法，研究了一天这个算，蛮难理解的，等真正理解后真的很有意思，很实用的一个算法

### 代码

```c
int maxSubArray(int* nums, int numsSize)
{
int i,j=1;
int*mark=(int*)malloc(sizeof(int)*numsSize);
mark[0]=nums[0];
for(i=1;i<numsSize;i++)
	{
	mark[i]=mark[i-1]+nums[i]>nums[i]?nums[i]+mark[i-1]:nums[i];
	}
int result=mark[0];
while(j<numsSize)
	{
	if(mark[j]>result)
		result=mark[j];
	j++;
	}
return result;
}
```