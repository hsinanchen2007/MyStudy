### 解题思路
![QQ图片20200321154901.png](https://pic.leetcode-cn.com/bae2789d2386001d0ed51da948e59362768ef325345bea8109c0bb87981d57c0-QQ%E5%9B%BE%E7%89%8720200321154901.png)
前后差为正负交替+1


### 代码

```c
int wiggleMaxLength(int* nums, int numsSize)
{
	int i;
	int ret=1;
	int flag=-1;
	if(numsSize<=2)
	{
		if(numsSize==2)
		{
			if(nums[0]==nums[1])
			{
				return 1;
			}
		}
		else
		{
			return numsSize;
		}
	}
	
	for(i=0;i<numsSize-1;i++)
	{
		if(nums[i+1]>nums[i])
		{
			if(flag==-1)
			{
				flag=0;
			}
			//第二个数大于第一个数(正负交替)
			if(flag==0)
			{
				flag=1;
				ret++;
			}
		}
		else if(nums[i+1]<nums[i])
		{
			if(flag==-1)
			{
				flag=1;
			}
			//第二个数小于第一个数(负正交替)
			if(flag==1)
			{
				flag=0;
				ret++;
			}
		}	
	}
    return ret;
}

```