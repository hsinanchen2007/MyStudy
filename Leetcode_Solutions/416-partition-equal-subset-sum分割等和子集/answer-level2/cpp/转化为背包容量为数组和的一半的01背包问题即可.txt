### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()==1)
            return false;
        int sum = 0;
        for(auto i : nums)
            sum += i;
        if(sum%2!=0)//特判
            return false;
        sum = sum/2;
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,0)); //dp[i][j]表示从范围0-i内能表示j这个值
        //初始化第一行
        for(int i=0;i<=sum;i++)
            if(nums[0]==i)
                dp[0][i] = 1; 
        //初始化第一列
        for(int j=0;j<nums.size();j++)
            dp[j][0] = 1;
        //转化为背包问题，即sum/2为背包总量
        for(int i=1;i<nums.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j<nums[i])
                    dp[i][j] = dp[i-1][j] ? 1:0;
                else
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-nums[i]] ? 1:0;
            }
            if(dp[i][sum]==1)
                return true;
        }
        return false;
        
    }
};
```