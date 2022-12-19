问题的本质是01背包问题，无论递归还是迭代 最终的本质是一样的
本题解法可以完全应用于322零钱兑换——https://leetcode-cn.com/problems/coin-change/
使用贪心算法 最主要的是在递归的开始就进行优化
在给定情况下，每一步都尽量选取大的平方数，保证每一步最大，即为最终的结果最小
并且在递归中加入剪枝，如果当前计数器的数量大于已经记录的最小参数就剪枝
优化了大部分重复的过程

![1.png](https://pic.leetcode-cn.com/7ee1a148ce75f78c925ee1f8706a2d33272d69f9425e6c184cde3e6e26a54d3c-1.png)


```
public class Solution {
	int[] nums;int result=Integer.MAX_VALUE;
	void back(int count,int number,int index) {
		if(number==0) {
			result=Math.min(result, count);
			return;
		}
		if(index==-1||number/nums[index]+count>=result)return;
		for(int j=number/nums[index];j>=0;j--) {
			back(count+j, number-nums[index]*j, index-1);
		}
		
	}
	
	  public int numSquares(int n) {
		  int num=0;
		for(int i=0;i*i<n;i++) {
		 num=i;	
		}  
		 if((num+1)*(num+1)==n) {return 1;}
		 int[] nums=new int[num];
		 for(int i=1;i<=num;i++) {
			 nums[i-1]=i*i;
		 }
		 this.nums=nums;
		 back(0, n, num-1);
		 
		return result;
	        
	    }
}
```

