 **动态规划的核心点：我来自哪，去往何方,也就是对应动规的自顶向下，自底向上**
1. 能被三整除有两种情况：
2. 自身为3倍数，余1+余2的数可被3整除，因此每次只需更新这三个值即可
```
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int dp[3]={0,0,0};
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%3==0){
                dp[1]+=nums[i];
                dp[0]+=nums[i];
                dp[2]+=nums[i];
            }
            if(nums[i]%3==1){
                int t=dp[0];
               if((nums[i]+dp[2])%3==0) dp[0]=max(dp[0],nums[i]+dp[2]);
                if((nums[i]+dp[1])%3==2)dp[2]=max(dp[2],dp[1]+nums[i]);
                if((nums[i]+t)%3==1)dp[1]=max(dp[1],t+nums[i]);
            }
            if(nums[i]%3==2){
                int t=dp[0];
                if((nums[i]+dp[1])%3==0)dp[0]=max(dp[0],dp[1]+nums[i]);
                if((nums[i]+dp[2])%3==1)dp[1]=max(dp[1],dp[2]+nums[i]);
                if((nums[i]+t)%3==2)dp[2]=max(dp[2],t+nums[i]);
            }
        }
        return dp[0];
    }
};
```
