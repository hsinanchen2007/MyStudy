# Rob II ->an intresting question

***In this question,it is a little difference of Rob I,because the fitst house and the last one is aside;***



**That is means we can not choose both of them , choose the first house or the last;
It is easy for us to think we can solve this question by dp of twice.
1.bigan with nums[0] but end by nums[len-2];
2.bigan with nums[1] entuil nums[len-1];**

```
class Solution {
public:
    int rob(vector<int>& nums) {
         int len=nums.size();
        int dp[len+1][2];
        if(len==0) return 0;
        if(len==1) return nums[0];
        if(len==2) return max(nums[0],nums[1]);
        int a,b;
        dp[0][1]=max(0,nums[0]);
        dp[1][0]=nums[0];
        dp[1][1]=nums[1];
        for(int i=2;i<len-1;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=max(dp[i-1][0]+nums[i],dp[i-1][1]);
        }
        
        a=max(dp[len-2][0],dp[len-2][1]);
        int dpp[len+1][2];
        dpp[1][1]=max(0,nums[1]);
        dpp[2][0]=nums[1];
        dpp[2][1]=nums[2];
        for(int i=3;i<len;i++){
            dpp[i][0]=max(dpp[i-1][0],dpp[i-1][1]);
            dpp[i][1]=max(dpp[i-1][0]+nums[i],dpp[i-1][1]);
        }
        
        b=max(dpp[len-1][0],dpp[len-1][1]);
        return max(a,b);
    }
};
```
