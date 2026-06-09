### 解题思路
//留着复盘

### 代码

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //0-1背包解法
        int sum = computeArraySum(nums);
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        int W = (sum + S) / 2;
        vector<int> dp(W + 1);
        dp[0] = 1;
        for (vector<int>::iterator iter = nums.begin(); iter < nums.end(); iter++)
        {
            for (int i = W; i >= *iter; i--)
            {
                dp[i] = dp[i] + dp[i - *iter];
            }
        }
        return dp[W];

    }
    //vector<int> iterator::iter
private:
    int computeArraySum(vector<int>& nums)
    {
        int sum = 0;
        for (vector<int>::iterator iter = nums.begin(); iter < nums.end(); iter++)
        {
            sum += *iter;
        }
        return sum;
    }
};
```