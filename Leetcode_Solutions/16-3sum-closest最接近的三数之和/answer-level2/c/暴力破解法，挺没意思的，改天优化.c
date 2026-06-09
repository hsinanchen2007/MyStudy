### 解题思路
此处撰写解题思路

### 代码

```c
int threeSumClosest(int* nums, int numsSize, int target){
	if(numsSize == 3)
		return nums[0]+nums[1]+nums[2];
	int i,j,k;
	int min,sum = nums[0]+nums[1]+nums[2];
	min=sum>target?sum-target:target-sum;
	int return_num = sum;
	for(i=0;i<numsSize-2;i++)
	{
		for(j=i+1;j<numsSize-1;j++)
		{
			for(k=j+1;k<numsSize;k++)
			{
				sum = nums[i]+nums[j]+nums[k];
				if(sum>target && sum-target<min)
				{
					min = sum - target;
					return_num = sum;
				}
				else if(sum<=target && target-sum<min)
                {
					min = target-sum;
					return_num = sum;
                }
			}
		}
	}
	return return_num;
}
```