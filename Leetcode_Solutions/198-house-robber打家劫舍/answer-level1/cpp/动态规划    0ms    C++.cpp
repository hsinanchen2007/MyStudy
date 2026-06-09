动态规划的题
class Solution {
    vector<int>dp;     //dp[i]表示到第i个房子为止能抢到的最大的金额
public:
    int rob(vector<int>& nums) {
	if(nums.size()==0)
		return 0;
	else if(nums.size()==1)
		return nums[0];
	else if(nums.size()==2)
		return nums[1]>nums[0]?nums[1]:nums[0];
	else {
		dp.push_back(nums[0]);
		dp.push_back(nums[1]>nums[0]?nums[1]:nums[0]);
		for(int i=2;i<nums.size();i++){
			dp.push_back((nums[i]+dp[i-2])>dp[i-1]?(nums[i]+dp[i-2]):dp[i-1]);
		}
		return dp[nums.size()-1]; 
	}	
}
};
