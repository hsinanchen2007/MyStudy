![image.png](https://pic.leetcode-cn.com/cc1a2ec4483519637a4aa4a53bce492140f360b2814aed49f1daa066703447dc-image.png)
明显的动态规划，写出状态转移方程：dp[i]=max(dp[i-1],dp[i-2]+nums[i])，时间复杂度O（n），空间复杂度O（n）
一开始以为这样就结束了，仔细想想可以更抠门一点，因为dp[i]仅仅为计算dp[i+1]和dp[i+2]提供了帮助，之后再也不会用到，所以算出dp[i+2]后就可以删掉dp[i]，所以我们的dp数组长度只需要为2，用i的奇偶来区分，空间复杂度降为O（1）
int massage(int* nums, int numsSize){
    if(numsSize==0)return 0;
    if(numsSize==1)return nums[0];
	int dp[2];
    dp[0]=nums[0];
    dp[1]=nums[1]>nums[0]?nums[1]:nums[0];
    int i;
    for(i=2;i<numsSize;i++){
    	dp[i%2]=dp[(i-1)%2]>dp[i%2]+nums[i]?dp[(i-1)%2]:dp[i%2]+nums[i];
	}
	return dp[(numsSize-1)%2];
}