
```cpp
class Solution {
public:
    //动态规划：dp数组储存最大抢劫量，dp[i]表示抢到第i个房间时的最大抢劫量
    //因为不能相邻抢劫，所以如果抢劫了i-1户，就不能抢劫第i户，或者是i-2户再加上当前户i
    //dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    //dp数组第一个值和第二个值分别为nums[0]和max(nums[0].nums[1])
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int> dp;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                dp.push_back(nums[0]);
            }else if(i==1){
                int tmp1=max(nums[0],nums[1]);
                dp.push_back(tmp1);
            }else{
                int tmp2=max(dp[i-1],dp[i-2]+nums[i]);
                dp.push_back(tmp2);
            }
        }
        return dp[nums.size()-1];
    }
};
```