### 解题思路

1. `dp[i]`为`nums[0]`到`num[i]`偷窃到的最高金额，含`nums[i]`
2. 保留最大的`dp[]`, `if(res<dp[i]) res=dp[i];`
-  也可以 `return max(dp[len-1],dp[len-2]);`   ///最高金额一定含最后两个房屋的其中一个
3. `dp[i]`为`nums[i]`加上`dp[i-2]`或`dp[i-3]`
-  即`dp[i]=max(dp[i-2],dp[i-3])+nums[i];`     
-  只能间隔一格或两格，若间隔三格，则可以取3个只间隔一格的房屋
- 
- 如`nums[]`为[2,1,1,2]时，`res=max(dp[2],dp[3])`
- 如`nums[]`为[2,7,9,3,1]时,`dp[0]=2`; `dp[1]=7`; `dp[2]=11`;
- [2,7,9,**3**,1], `dp[3]=max(dp[0],dp[1])+3`;
- [2,7,9,3,**1**], `dp[4]=max(dp[1],dp[2])+1`;

### 代码
```
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int len=nums.size();
        if(len==0) return 0;
        if(len==1) return nums[0];
        if(len==2) return max(nums[0],nums[1]);
        if(len==3) return max(nums[0]+nums[2],nums[1]);

        vector<int>dp(len,0);
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[2]+nums[0];

        int res=max(dp[1],dp[2]);
        for(int i=3;i<len;i++)
        {
            dp[i]=max(dp[i-2],dp[i-3])+nums[i];
            if(res<dp[i]) res=dp[i];
        }
        return res;
    }
};
```