### 解题思路
分析：

先转换一下问题：此题可以理解为，取出若干个数，使其之和为数组总和的一半（数组总和为奇数直接return false）

于是dp常规分析:

* 状态：元素，总值
* 选择：当前元素选与不选
* dp数组含义：dp\[i][j]表示前i个元素可否选出和值恰为j的子集
* $dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j]$（就是选与不选！）
* base case: $dp[i][0] = true, dp[0][j] = false(j\neq 0)$

### 代码

```cpp
class Solution {
public:
    //此题可以理解为，取出若干个数，使其之和为数组总和的一半（数组总和为奇数直接return false）
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
        //base case:
        for(int i = 0; i <= n; i++) dp[i][0] = true;
        for(int i = 1; i <= target; i++) dp[0][i] = false;
        //方程
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                //不能直接写这句话： dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                //因为j - nums[i - 1]的值可能小于0
                if(j >= nums[i - 1]) dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];  //就是选与不选！
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }
};
```