1. S的正负没有影响（如果S为负，只需要将全部符号反向即可），可以对S取绝对值
2. 首先设所有符号均为正，此时得到nums 的和sum；如果sum < S， 方法数为0；
3. diff = S - sum;
3. 如果一个数的符号变成负号，等于sum - 2 * nums[i]，所以如果diff是奇数，方法数也为0。 
4. 再变更符号，使得 diff = (sum - S) / 2; 
4. 问题就变成了一个背包问题，将nums中的数放进背包，使得和为diff，问有多少种方法。
```
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
		
		int sum = 0;
		
        sum = accumulate(nums.begin(), nums.end(), sum);

		int diff = sum - abs(S); //差

        if(diff < 0 || diff % 2)//不可能存在的情况
        {
            return 0;
        }
		
        diff /= 2;

        vector<int> pre(diff + 1, 0);
		vector<int> dp(diff + 1, 0);
		
		pre[0] = 1;
        dp[0] = 1;

		for(const auto &n : nums)
		{
			for(int i = 0; i <= diff; i++)
			{
				if(pre[i] != 0)
				{
					if(i + n <= diff)
					{
						dp[i + n] += pre[i];
					}
				}
			}

            pre = dp;
		}
		
		return dp[diff];
		
    }
};
```
