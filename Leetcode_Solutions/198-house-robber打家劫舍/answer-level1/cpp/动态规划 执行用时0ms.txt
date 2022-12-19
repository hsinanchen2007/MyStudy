### 解题思路
dp[i]是偷到nums[i]后就收手能挣到的最大值。
于是有
dp[i]=max(dp[i-3],dp[i-2])+nums[i];
含义是：偷nums[i]的上一个一定是num[i-3]或者nums[i-2]，max(dp[i-3],dp[i-2])是偷nums[i]之前的最优解。
到达终点后，比较最后dp数组最后两个的数值，输出最大值。

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        if(n==1)
        return nums[0];
        if(n==2)
        return max(nums[0],nums[1]); //预处理
        vector<int>dp(n,0);    //dp[i]是偷到nums[i]后收手能挣到的最大值
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        dp[2]=max(nums[1],nums[0]+nums[2]);
        for(int i=3;i<n;i++)//偷nums[i]之前，肯定才偷了nums[i-3]或者nums[i-2]，得下式
            dp[i]=max(dp[i-3],dp[i-2])+nums[i]; 
        return max(dp[n-1],dp[n-2]);
    }
};
```