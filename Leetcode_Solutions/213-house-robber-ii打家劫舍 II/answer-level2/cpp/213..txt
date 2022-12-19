复杂度O(n),空间复杂度O(1),4ms,8.5MB  
```
class Solution {
public:
    int dp[2][2][2];//1~i 第i个选/不选，第1个选/不选的最大值
    int rob(vector<int>& nums) {
        int n=nums.size();if(n==0)return 0;
        dp[1][1][1]=nums[0];dp[1][0][0]=0;
        int t=0;
        for(int i=2;i<n;i++){
            //第i个选
            dp[t][1][0]=dp[t^1][0][0]+nums[i-1];
            if(i==2)dp[t][1][1]=0;
            else dp[t][1][1]=dp[t^1][0][1]+nums[i-1];
            
            //第i个不选
            dp[t][0][1]=max(dp[t^1][0][1],dp[t^1][1][1]);
            dp[t][0][0]=max(dp[t^1][0][0],dp[t^1][1][0]);t^=1;
        }
        
        dp[t][1][0]=dp[t^1][0][0]+nums[n-1];
        dp[t][0][0]=max(dp[t^1][1][0],dp[t^1][0][0]);
        dp[t][0][1]=max(dp[t^1][1][1],dp[t^1][0][1]);

        return max(dp[t][0][1] ,max(dp[t][1][0],dp[t][0][0]));
    }
};
```