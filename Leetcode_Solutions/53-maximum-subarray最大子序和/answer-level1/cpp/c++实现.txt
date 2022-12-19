```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            if(i>0&&dp[i-1]<0){
                dp[i] = nums[i];
            }else{
                dp[i] = dp[i-1]+nums[i];
            }
        }
        int max = INT_MIN;
        for(int i=0;i<dp.size();i++){
            if(dp[i]>max){
                max = dp[i];
            }
        }
        return max;
    }
};
```
```
//贪心法
class Solution{
    public:
        int maxSubArray(vector<int> nums){
            int res = INT_MIN;
            int sum = 0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                res = max(res,sum);
                if(sum<0){
                    sum=0;
                }
            }
            return res;
        }
};
```

