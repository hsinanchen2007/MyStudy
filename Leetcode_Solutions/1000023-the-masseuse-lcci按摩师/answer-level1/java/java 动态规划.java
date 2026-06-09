1、定义状态
dp[i] 表示数组0到i区间内最大和

2、状态转移方程
  i-1步没有预约则dp[i]是dp[i-2]状态加上本次预约值
     dp[i]=dp[i-2]+nums[i]
  i-1步预约了则nums[i]不能预约
     dp[i]=dp[i-1]
 最终方程为dp[i]=max{dp[i-2]+nums[i],dp[i-1]}

3、初始化
  因方程中涉及i-2则需初始化dp[0]和dp[1];
   dp[0] 只有nums[0]一个可选，最大只能选上
     dp[0]=nums[0]
   dp[1] 则选择nums[0]和nums[1]的较大者

4、考虑边界情况
   输入为null、输入长度为0、输入长度为1


	    public int massage(int[] nums) {
	    	if(nums==null||nums.length==0) return 0;
	    	if(nums.length<2) return nums[0];
	    	int [] dp=new int[nums.length];
	    	dp[0]=nums[0];
	    	dp[1]=nums[0]>nums[1]? nums[0]:nums[1];
	    	for(int i=2;i<nums.length;i++){
	    		dp[i]=dp[i-1]>(dp[i-2]+nums[i])?dp[i-1]:(dp[i-2]+nums[i]);
	    	}
	    	return dp[nums.length-1];

	    }


