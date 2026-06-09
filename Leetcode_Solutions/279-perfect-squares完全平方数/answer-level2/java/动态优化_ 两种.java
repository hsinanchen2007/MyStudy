- [零钱兑换](https://leetcode-cn.com/problems/coin-change/solution/)
### 自顶向下(备忘录法)
```java
class Solution {
    private Integer[] dp;
    //本题和换硬币一样 换汤不换药
	public int numSquares(int n) {
		// 备忘录法
    	this.dp=new Integer[n+1];
    	// 构建"硬币"
    	int tmpN=1;
    	ArrayList<Integer> nums= new ArrayList<Integer>();
    	while(tmpN*tmpN<=n) {
    		nums.add(tmpN*tmpN);
    		tmpN++;
    	}// 构建"可找硬币们"
        dp[n]=n; // 最大要n个1
    	for(int i=0;i!=nums.size();i++) {
    		dp[n]=Math.min(dp[n], 1+recur(nums,n-nums.get(i)));
    	}
    	return dp[n];
    }

	private int recur(ArrayList<Integer> nums, int target) {
		if(dp[target]!=null) return dp[target];
		dp[target]=target;
		for(int i=0;i!=nums.size()&&nums.get(i)<=target;i++) {
			dp[target]=Math.min(dp[target],1+recur(nums,target-nums.get(i)));
		}
		return dp[target];
	}
}
```
### 自底向上
- dp[当前金额]=dp[当前金额-使兑换硬币数最少的面额]+1
```java
class Solution {
    //本题和换硬币一样 换汤不换药
	public int numSquares(int n) {	
    	// 构建"硬币"
    	int tmpN=1;
    	ArrayList<Integer> nums= new ArrayList<Integer>();
    	// 构建"可找硬币面额"
    	while(tmpN*tmpN<=n) {
    		nums.add(tmpN*tmpN);
    		tmpN++;
    	}
    	// 自底向上
    	Integer[]dp=new Integer[n+1];
    	for(int i=0;i!=n+1;i++) {
    		dp[i]=i;
    		for(int j=0;j!=nums.size()&&i>=nums.get(j);j++) {
    			dp[i]=Math.min(dp[i-nums.get(j)]+1,dp[i]); // 最少找硬币数
    		}
    	}
    	return dp[n];
    }
}
```