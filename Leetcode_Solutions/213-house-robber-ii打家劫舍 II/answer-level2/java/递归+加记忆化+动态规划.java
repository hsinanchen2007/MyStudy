### 1. 递归（超时）
首先想到的是递归的解法，分为两种情况，一种是不偷第一个房子，另一种是不偷最后一个房子，然后将这两种的最大收益作比较，返回大者就好了，还有一点要考虑的就是对于获得某个区间中的最大收益怎么获得，其实和最初的打家劫舍一样，也是分为两种情况，第一种选择偷取当前的房子i，然后偷取i+2的房子，另一种是不偷当前的房子，然后偷取i+1的房子，这两个的较大者就是这个区间所能获得的最大的收益

```
class Solution {
    //找到某个区间内可以获得的最大的收益
	private int dfs(int[]nums,int l,int r) {
		//如果没有房子，返回0
		if(l>r) return 0;
				
		//如果房子数为1，就直接返回就好了
		if(l==r) return nums[l];
		
		//两种情况，要么是偷取当前的房子，要么取偷剩下的房子
		int one=nums[l]+dfs(nums, l+2, r);
		int two=dfs(nums, l+1, r);
		
		//返回两者的最大值
		return Math.max(one, two);
	}
	
    public int rob(int[] nums) {
        //递归来写一下
    	int n=nums.length;
    	
    	//如果房子的个数为0，收益为0
    	if(n==0) return 0;
    	
        //如果只有一个房子，返回这个房子的收益就好了
    	if(n==1) return nums[0];
        
    	//分两种情况，第一种不偷最后一个房子，第二种不偷第一个房子
    	int one=dfs(nums, 1, n-1);
    	int two=dfs(nums, 0, n-2);
    	
    	//返回两者的较大者
    	return Math.max(one, two);
    }
}
```
### 2.记忆化搜索（通过）
对于上面的递归，我们就一个实例来写一下它的递归树，例如区间为[3,1,2,4,5,6],我们看一下不偷第一个房子所对应的递归树
![image.png](https://pic.leetcode-cn.com/8734947093cf64697bf3d719978f8bbea64184a67b5be5c745e660f34dafb700-image.png)
可以看出，这其中对于每一个区间的最大值的求解可能会包含很多重复的计算，所以这里为了防止这样重复的计算，我们使用备忘录法来解决
```
class Solution {
    //设置一个memo存储某个区间的最大的收益
	int[][]memo;
	
	//找到某个区间内可以获得的最大的收益
	private int dfs(int[]nums,int l,int r) {
		//如果没有房子，返回0
		if(l>r) return 0;
				
		//如果房子数为1，就直接返回就好了
		if(l==r) return nums[l];
		
		//如果有存储的这个区间的最大的收益，直接返回就好了
		if(memo[l][r]!=-1) return memo[l][r];
		
		//两种情况，要么是偷取当前的房子，要么取偷剩下的房子
		int one=nums[l]+dfs(nums, l+2, r);
		int two=dfs(nums, l+1, r);
		
		//存储这个区间的最大值
		memo[l][r]=Math.max(one, two);
		
		//返回两者的最大值
		return Math.max(one, two);
	}
	
    public int rob(int[] nums) {
        //递归来写一下
    	int n=nums.length;
    	
    	//如果房子的个数为0，收益为0
    	if(n==0) return 0;
    	
    	//如果只有一个房子，返回这个房子的收益就好了
    	if(n==1) return nums[0];
    	
    	memo=new int[n][n];
    	for(int i=0;i<n;i++) {
    		Arrays.fill(memo[i], -1);
    	}
    	
    	//分两种情况，第一种不偷最后一个房子，第二种不偷第一个房子
    	int one=dfs(nums, 1, n-1);
    	int two=dfs(nums, 0, n-2);
    	
    	//返回两者的较大者
    	return Math.max(one, two);
    }
}
```
### 3. 动态规划（通过）
由上面的递归树可以看出来，这个问题的原问题的最优解来源于子问题的最优解，并且其中包含有大量的重复的子问题，所以这里可以使用动态规划来解决，设置一个dp[i]表示[l,i]的房子的最大的收益，l为区间的起始位置，状态转移方程由上面的递归树从下向上看就可以得出,也就是dp[i]=max(dp[i-1],nums[i]+dp[i-2]),分别计算[0,n-2]和[1,n-1]的最大的收益，返回一个较大者
```
class Solution {
    int bottomUp(int[]nums,int l,int r) {
		//对这个区间进行判断
		if(l>r) return 0;
		if(l==r) return nums[l];
		
		//设置一个dp数组存储这个区间中的最大的收益
		//dp[i]表示[l-i]的最大的收益
		//状态转移方程为dp[i]=max(dp[i-1],nums[i]+dp[i-2])
		
		//对dp数组进行构造并初始化
		int[]dp=new int[r+1];
		
		dp[l]=nums[l]; dp[l+1]=Math.max(nums[l+1], nums[l]);
		
		for(int i=l+2;i<=r;i++) {
			dp[i]=Math.max(dp[i-1], nums[i]+dp[i-2]);
		}
		
		return dp[r];
	}
	
    public int rob(int[] nums) {
        //获得数组的长度
    	int n=nums.length;
    	
    	if(n==0) return 0;
    	if(n==1) return nums[0];
    	
    	int one=bottomUp(nums, 1, n-1);
    	int two=bottomUp(nums, 0, n-2);
    	
    	return Math.max(one, two);
    }
}
```
