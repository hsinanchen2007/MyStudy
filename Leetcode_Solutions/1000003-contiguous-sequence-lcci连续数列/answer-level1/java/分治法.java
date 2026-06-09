### 解题思路
分治的基本思想就是将大问题化解为小问题，小问题继续化解，复杂问题简单化。
首先分析如下：
	任意一个序列，最大子序列只有3种情况
	1.出现在数组左边；
	2.出现在数组右边；
	3.出现在数组中间部分，即横跨左右；
那么我们要求的其实就是这三者中的最大值，即求数组左边的最大值，数组右边的最大值，数组中间部分的最大值。
将数组划分为左右两部分，便可求得左右子数组的最大，在求左右子数组的过程中，leftsum,rightsum均从中间向两端相加，那么
leftsum+rightsum即为中间部分相加的最大值。
代码如下：

### 代码

```java
class Solution {
  public int maxSubArray(int[] nums) {
    		return maxSub(nums,0,nums.length-1);
    }
    public static int maxSub(int[]nums,int left,int right )
    {
		//一定将左右边界最大初始化为MIN_VALUE，初始化为0的时候全为负数过不去
		int maxleftbordersum =  Integer.MIN_VALUE,maxrightbordersum = Integer.MIN_VALUE; 
		int leftmaxsum = Integer.MIN_VALUE,rightmaxsum = Integer.MIN_VALUE;				
		int leftbordersum = 0,rightbordersum = 0;
		
		int mid = left+(right-left)/2;
		if(left==right)
		{
			return nums[left];
		}
		leftmaxsum = maxSub(nums,left,mid);		//计算得到左子数组的最大值
		rightmaxsum= maxSub(nums,mid+1,right);	//计算得到右子数组的最大值
		
		for(int i = mid;i >= left ;i--)		//一定要从中间向两端加！！！
		{
			leftbordersum += nums[i];
			if(leftbordersum > maxleftbordersum)
				maxleftbordersum = leftbordersum;
		}
		
		for(int i = mid+1 ;i <= right;i++)
		{
			rightbordersum += nums[i];
			if(rightbordersum > maxrightbordersum)
				maxrightbordersum = rightbordersum;
		}
		//返回三者最大值
		return Integer.max(leftmaxsum,Integer.max(rightmaxsum,maxleftbordersum+maxrightbordersum));
    }
}
```