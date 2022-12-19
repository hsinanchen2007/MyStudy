### 解题思路
这个题目可以用动态规划的方法求解：

最优解dp[i]表示如果小偷从第1个偷到第i个家庭，最高的金额可以为多少
而根据题意可以知道：
dp[i] = max( dp[i-2] + nums[i], dp[i-1] )

也就是说，因为不能相邻，小偷到了第i个家庭，最高的金额要么是他偷到第i-1个家庭时的最高金额，要么是偷到第i-2个家庭时的最高金额再加上第i个家庭的金额。

至此问题解决。
### 代码

```cpp
//dp[n] = max( dp[n-2]+nums[n], dp[n-1] );

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
		int dp_temp,i;
        int len=nums.size();
        if(len==0)
            return 0;
        else
            if(len==1)
                return nums[0];
		dp.push_back(nums[0]);
		if(nums[0]>nums[1])
			dp.push_back(nums[0]); 
		else
			dp.push_back(nums[1]); 
		
		for(i=2;i<len;i++)
		{
			dp_temp = dp[i-2]+nums[i];
			if(dp_temp>dp[i-1])
				dp.push_back(dp_temp);
			else
				dp.push_back(dp[i-1]);
		}
		return dp[len-1];
    }
};

```