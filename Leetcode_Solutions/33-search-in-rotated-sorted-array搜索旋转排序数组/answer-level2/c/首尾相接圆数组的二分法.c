### 解题思路
首先把整个数组想成一个首尾相接的圆。这样子平分之后，肯定有一个半圆的数是单调递增的。
二分法后，先判断中间那个是不是要找的数，然后用条件找出那个单调递增的半圆，因为单调递增就可以判断范围了。
如果数在范围里面，就取这个半圆，舍弃另外一半；若数不在里面，则舍弃这个半圆，取另外一半。（用mid灵活赋值）
以此类推，直到最后。

### 代码

```c
int search(int* nums, int numsSize, int target)
{

	int left=0,right=(numsSize-1);//想象一个首尾相接的圆，left是头，right是尾

	while(left<=right)
	{
		int mid=(left+right)/2;//取中点
		if(target==nums[mid])
		{
			return mid;
		}
		if(nums[mid]>=nums[left])//判断哪半边圆是单调递增的
		{
			if(target>=nums[left]&&target<nums[mid])//看看数在不在这半边圆里面
			{
				right=mid-1;
			}
			else
			{
				left=mid+1;
			}
		}
		else
		{
			if(target<=nums[right]&&target>nums[mid])
			{
				left=mid+1;
			}
			else
			{
				right=mid-1;
			}
		}
	}

	return -1;
}
```