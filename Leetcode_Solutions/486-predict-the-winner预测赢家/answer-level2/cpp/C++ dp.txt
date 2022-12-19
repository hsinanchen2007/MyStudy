### 解题思路
这题比较奇特，设的dp[i][j]是nums[i,j]的时候，双方间的分数最大差值，这个dp可能是先手的，也可能是后手的，所以有
dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);

dp[0][nums.size()-1] >= 0  就是我们要的结果

剩下的优化还可以用dp压缩一下，因为后面只依赖前一次的结果。

### 代码

```cpp
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() == 1) return true;
        vector<vector<int>> dp = vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
        for (long s=nums.size() - 1; s >=0; s--) {
            for (long e = s+1; e<nums.size(); e++) {
                dp[s][e] = max(nums[s] - dp[s+1][e], nums[e] - dp[s][e-1]);
            }
        }
        return dp[0][nums.size()-1] >= 0;
    }
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() == 1) return true;
        vector<int> dp = vector<int>(nums.size(), 0);
        for (long s=nums.size() - 1; s >=0; s--) {
            for (long e = s+1; e<nums.size(); e++) {
                dp[e] = max(nums[s] - dp[e], nums[e] - dp[e-1]);
            }
        }
        return dp[nums.size()-1] >= 0;
    }
};
```