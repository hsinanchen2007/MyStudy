![image.png](https://pic.leetcode-cn.com/f063400fc81ed3b35f426afa7567298a4080197781ac06fb69b88a38db8c070a-image.png)
```
class Solution {
public:
    int rob(vector<int>& nums) {
        int num_size=nums.size();
        if(num_size==0)
        return 0;
        if(num_size==1)
        return nums[0];
        int dp[num_size]={0};
        
        dp[0]=nums[0] ;
        dp[1]=nums[1];
        int dp_max=dp[0];
        for(int i(2);i<num_size;i++)
        {
            if(dp_max>dp[i-2])
            dp[i]=dp_max+nums[i];
            else
            {
                dp[i]=dp[i-2]+nums[i];
                dp_max=dp[i-2];
            }
        }
        int max_result(-100);
        for(int i(0);i<num_size;i++)
        {
            if(dp[i]>max_result)
            {
                max_result=dp[i];
            }
        }
        return max_result;
    }
};
```

